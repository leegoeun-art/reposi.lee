#include <stdio.h>

int main(void)
{  
  def swap_case(input_str):
    result_str = ""
    for char in input_str:
        if char.isupper():
            result_str += char.lower()
        elif char.islower():
            result_str += char.upper()
        else:
            result_str += char
    return result_str

if __name__ == "__main__":
    user_input = input("Input> ")
    output_str = swap_case(user_input)
    print("Output>", output_str)
}
