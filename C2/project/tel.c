#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

#define MAX_ENTRIES 100

//전화번호부 항목을 나타내는 구조체 정의
typedef struct {
	char name[30];
	char phone[20];
	char memo[50];
} Entry;

//전화번호부 배열
Entry phonebook[MAX_ENTRIES];
// 전화번호부 항목 수
int entry_count = 0;

//data.txt 파일에서 전화번호부를 로드하는 함수(데이터를 읽어오는 함수) 
void load_data() {
	FILE *file = fopen("data.txt", "r"); //파일 열기
	if (!file) {
		perror("Could not open data.txt");
		exit(1); //파일 열기 실패하면 프로그램 종료 
		}

	char line[100];
	while (fgets(line, sizeof(line), file)) { // 파일에서 한 줄씩 읽어오기 
		if (entry_count >= MAX_ENTRIES) { 
			break;
		}
		
		Entry entry;
		char *token = strtok(line, ":"); // ":"를 기준으로 문자열 나누기 
		if (token) {
			strcpy(entry.name, token); //이름 저장 
		}
		
		token = strtok(NULL, ":");
		if (token) {
			strcpy(entry.phone, token); //전화번호 저장
		}
	
		token = strtok(NULL, ":");
		if (token) {
			strcpy(entry.memo, token); //메모 저장 
		} else {
			strcpy(entry.memo, ""); //메모가 없을 경우 빈 문자열로 저장
		}
	
		phonebook[entry_count++] = entry; // 전화번호부에 항목 추가 
	}
	fclose(file); //파일 닫기 
}

//data.txt 파일에 전화번호부 (데이터)를 저장하는 함수
void save_data() {
	FILE *file = fopen("data.txt", "w"); //파일 열기 
	if (!file) {
		perror("Could not open data.txt");
		return; //파일 열기 실패하면 함수 종료 
	} 

	for (int i = 0; i < entry_count; i++) {
		fprintf(file, "%s:%s:%s\n", phonebook[i].name, phonebook[i].phone, phonebook[i].memo);
	}
	fclose(file); //파일 닫기 
}

//ncurses 초기화 함수
void init_ncurses() {
	initscr(); //ncurses 초기화 
	cbreak(); //입력을 즉시 전달 
	noecho(); //입력을 화면에 출력하지 않음 
	keypad(stdscr, TRUE); // 특수 키 입력을 가능하게 함  
}

//ncureses 종료 함수
void end_ncurses() {
	endwin(); //ncurses 종료
} 


//메뉴를 화면에 표시하는 함수
void display_menu() {
	clear(); //화면 지우기 
	mvprintw(0, 0, "Phonebook Menu:"); //메뉴표시 
	mvprintw(1, 0, "1. Search");
	mvprintw(2, 0, "2. Add");
	mvprintw(3, 0, "3. Delete");
	mvprintw(4, 0, "4. List");
	mvprintw(5, 0, "5. Exit");
	refresh(); // 화면 갱신 
}

//메뉴 선택 함수
int get_menu_choice() {
	int choice = getch(); //키 입력 받기 
	return choice - '0'; // ascii 코드를 숫자로 변환하여 반환
}

//전화번호부에서 이름을 검색하는 함수 
void search_entry() {
	char name[30];
	mvprintw(7, 0, "Enter name to search: ");
	echo();
	getstr(name); // 이름 입력 받기 
	noecho();
	clear();
	for (int i = 0; i<entry_count; i++) {
		if (strcmp(phonebook[i].name, name) == 0) { // 이름이 일치하는 항목 찾기 
			mvprintw(8, 0, "Found: %s, %s, %s", phonebook[i].name, phonebook[i].phone, phonebook[i].memo);
			refresh();
			getch();
			return;
		}
	}		
	mvprintw(8, 0, "No entry found with name: %s", name);
	refresh();
	getch();
}

//전화번호부에 항목을 추가하는 함수 
void add_entry(){
	if (entry_count >= MAX_ENTRIES) {
		mvprintw(7, 0, "Phonebook is full!");
		refresh();
		getch();
		return;
	}

	Entry new_entry;
	mvprintw(7, 0, "Enter name: ");
	echo();
	getstr(new_entry.name); // 이름 입력 받기 
	mvprintw(8, 0, "Enter phone: ");
	getstr(new_entry.phone); // 전화번호 입력 받기 
	mvprintw(9, 0, "Enter memo: ");
	getstr(new_entry.memo); // 메모 입력 받기 
	noecho();

	phonebook[entry_count++] = new_entry; // 전화번호부에 새 항목 추가 
	mvprintw(10, 0, "Entry added."); 
	refresh();
	getch();
}

// 전화번호부에서 항목을 삭제하는 함수  
void delete_entry() {
	char name[30];
	mvprintw(7, 0, "Enter name to delete: ");
	echo();
	getstr(name); // 삭제할 항목의 이름 입력 받기 
	noecho();
	for (int i = 0; i < entry_count; i++) {
		if (strcmp(phonebook[i].name, name) == 0) { // 입력한 이름과 일치하는 항목 찾기
			for (int j = i; j < entry_count - 1; j++) {
				phonebook[j] = phonebook[j+1]; // 해당 항목 이후의 항목들을 한 칸씩 앞으로 당기기
			}
			entry_count--; // 전화번호부 항목 수 감소 
			mvprintw(8, 0, "Entry deletd.");
			refresh();
			getch();
			return; 
		}
	}
	mvprintw(8, 0, "No entry found with name: %s", name); //해당 이름 가진 항목 없을 경우 메시지 출력
	refresh();
	getch();
}

//리스트 출력 기능 구현 함수
void list_entries(){
	clear(); // 화면 지우기 
	for (int i = 0; i < entry_count; i++) {
		mvprintw(i, 0, "%s: %s: %s", phonebook[i].name, phonebook[i].phone, phonebook[i].memo);
	} 
	refresh(); // 화면 갱신 
	getch(); // 사용자 입력 대기 
}

//프로그램 실행 함수 (메인 함수) 
int main() {
	load_data(); //데이터 로드 
	init_ncurses(); //ncurses 초기화 

	int choice;
	while (1) { // 무한 루프로 메뉴 표시 및 선택 반복 
		display_menu(); //메뉴표시 
		choice = get_menu_choice(); //메뉴 선택 
		
		switch (choice) {
			case 1: 
				search_entry(); // 검색 기능 실행 
				break;
			case 2:
				add_entry(); //추가 기능 실행 
				break;
			case 3:
				delete_entry(); // 삭제 기능 실행 
				break;
			case 4:
				list_entries(); // 목록 보기 기능 실행 
				break;
			case 5:
				save_data(); // 프로그램 종료 시 데이터 저장 
				end_ncurses(); //ncurses 종료 
				return 0; // 프로그램 종료
			default:
				mvprintw(7, 0, "Invalid choice. Please try again."); //잘못된 선택일 경우 메시지 출력 
				refresh();
				getch();
		}
	}

	end_ncurses(); // ncurses 종료 
	return 0; //프로그램 종료 
}
