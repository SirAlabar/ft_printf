#!/usr/bin/python3

import subprocess
import sys
import os
try:
    from termcolor import colored
except ImportError:
    def colored(text, color):
        return text

class PrintfTester:
    def __init__(self):
        self.total_tests = 0
        self.passed_tests = 0
        
    def compile_test_program(self, format_str, args=None):
        with open('test_printf.c', 'w') as f:
            f.write(f'''
            #include "include/ft_printf.h"
            #include <stdio.h>
            #include <limits.h>
            
            int main(void)
            {{
                int ret1, ret2;
                
                printf("Original output: ");
                ret1 = printf("{format_str}"{', ' + args if args else ''});
                printf("\\nOriginal return: %d\\n", ret1);
                
                printf("Your output: ");
                ret2 = ft_printf("{format_str}"{', ' + args if args else ''});
                printf("\\nYour return: %d\\n", ret2);
                
                return (ret1 == ret2 ? 0 : 1);
            }}
            ''')
        
        compile_cmd = "cc -Wall -Wextra -Werror test_printf.c -L. -lftprintf -o test_program"
        try:
            result = subprocess.run(compile_cmd, shell=True, capture_output=True, text=True)
            if result.returncode != 0:
                print(colored(f"Erro ao compilar teste: {format_str}", "red"))
                print(result.stderr)
                return False
            return True
        except Exception as e:
            print(colored(f"Erro ao compilar: {e}", "red"))
            return False

    def run_test(self, format_str, args=None, description=""):
        self.total_tests += 1
        
        if not self.compile_test_program(format_str, args):
            return
        
        try:
            result = subprocess.run("./test_program", capture_output=True, text=True)
            output_lines = result.stdout.split('\n')
            
            original_output = output_lines[0].replace("Original output: ", "")
            original_return = int(output_lines[1].replace("Original return: ", ""))
            ft_output = output_lines[2].replace("Your output: ", "")
            ft_return = int(output_lines[3].replace("Your return: ", ""))
            
            if original_output == ft_output and original_return == ft_return:
                self.passed_tests += 1
                status = colored("OK", "green")
            else:
                status = colored("KO", "red")
            
            print("\n" + "="*50)
            print(f"Test {self.total_tests}: {description}")
            print(f"Format: {format_str}")
            if args:
                print(f"Args: {args}")
            print(f"Expected output: [{original_output}]")
            print(f"Expected return: {original_return}")
            print(f"Your output:     [{ft_output}]")
            print(f"Your return:     {ft_return}")
            print(f"Status: {status}")
            
        except Exception as e:
            print(colored(f"Erro ao executar teste: {str(e)}", "red"))
            print("Output completo:")
            print(result.stdout)
        finally:
            try:
                os.remove("test_printf.c")
                os.remove("test_program")
            except:
                pass

    def print_summary(self):
        print("\n" + "="*50)
        print(f"Total tests: {self.total_tests}")
        print(f"Passed: {self.passed_tests}")
        print(f"Failed: {self.total_tests - self.passed_tests}")
        percentage = (self.passed_tests / self.total_tests) * 100 if self.total_tests > 0 else 0
        print(f"Success rate: {percentage:.2f}%")
        print("="*50)

def main():
    tester = PrintfTester()
    
    # Testes básicos
    print(colored("\n1. Testes básicos...", "yellow"))
    tester.run_test("Simple Test", None, "String simples sem argumentos")
    tester.run_test("Test %%", None, "Porcentagem escapada")
    tester.run_test("%%d", None, "Porcentagem escapada com especificador")
    
    # Testes de strings
    print(colored("\n2. Testes de strings...", "yellow"))
    tester.run_test("%s", '"test"', "String básica")
    tester.run_test("%s %s", '"Hello", "World"', "Duas strings")
    tester.run_test("The word is: %s", '"test"', "String com texto")
    
    # Testes de números
    print(colored("\n3. Testes de números...", "yellow"))
    tester.run_test("%d", "42", "Número positivo")
    tester.run_test("%d", "-42", "Número negativo")
    tester.run_test("%d", "0", "Zero")
    tester.run_test("%i", "42", "Número com %%i")
    
    # Testes de unsigned
    print(colored("\n4. Testes de unsigned...", "yellow"))
    tester.run_test("%u", "42", "Unsigned pequeno")
    tester.run_test("%u", "0", "Unsigned zero")
    
    # Testes de hexadecimal
    print(colored("\n5. Testes de hexadecimal...", "yellow"))
    tester.run_test("%x", "255", "Hex ff minúsculo")
    tester.run_test("%X", "255", "Hex FF maiúsculo")
    tester.run_test("%x", "0", "Hex zero")
    
    # Testes mistos
    print(colored("\n6. Testes mistos...", "yellow"))
    tester.run_test("Number: %d String: %s", "42, \"test\"", "Número e string")
    tester.run_test("%d %s %x", "42, \"test\", 255", "Vários tipos")
    tester.run_test("100%%", None, "Porcentagem literal")
    
    # Prints the final summary
    tester.print_summary()

if __name__ == "__main__":
    main()