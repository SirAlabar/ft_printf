#!/usr/bin/python3

import subprocess
import sys
import os
from termcolor import colored

class PrintfTester:
    def __init__(self):
        self.total_tests = 0
        self.passed_tests = 0
        
    def compile_test_program(self, test_case):
        # Cria um arquivo temporário com o caso de teste
        with open('test_printf.c', 'w') as f:
            f.write('''
            #include "ft_printf.h"
            #include <stdio.h>
            
            int main(void)
            {
                int ret1, ret2;
                
                ret1 = printf("''' + test_case + '''");
                printf("\\n[RET1=%d]\\n", ret1);
                ret2 = ft_printf("''' + test_case + '''");
                printf("\\n[RET2=%d]\\n", ret2);
                return (0);
            }
            ''')
        
        # Compila o programa de teste
        compile_cmd = "cc -Wall -Wextra -Werror test_printf.c -L. -lftprintf -o test_program"
        try:
            subprocess.run(compile_cmd, shell=True, check=True, capture_output=True)
            return True
        except subprocess.CalledProcessError:
            print(colored(f"Erro ao compilar teste: {test_case}", "red"))
            return False

    def run_test(self, test_case, description=""):
        self.total_tests += 1
        
        if not self.compile_test_program(test_case):
            return
        
        try:
            # Executa o programa de teste
            result = subprocess.run("./test_program", capture_output=True, text=True)
            
            # Separa as saídas e retornos
            output = result.stdout.split('\n')
            original_output = output[0]
            original_return = int(output[1].split('=')[1][:-1])
            ft_output = output[2]
            ft_return = int(output[3].split('=')[1])
            
            # Compara resultados
            if original_output == ft_output and original_return == ft_return:
                self.passed_tests += 1
                status = colored("OK", "green")
            else:
                status = colored("KO", "red")
            
            # Mostra resultados
            print("\n" + "="*50)
            print(f"Test {self.total_tests}: {description}")
            print(f"Input: {test_case}")
            print(f"Expected output: [{original_output}] (return: {original_return})")
            print(f"Your output:     [{ft_output}] (return: {ft_return})")
            print(f"Status: {status}")
            
        except Exception as e:
            print(colored(f"Erro ao executar teste: {e}", "red"))
        
        # Limpa arquivos temporários
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
    basic_tests = [
        ("%s", '"Hello"'),
        ("%d", "42"),
        ("%i", "-42"),
        ("%u", "4294967295"),
        ("%x", "255"),
        ("%X", "255"),
        ("%p", "(void *)0x12345"),
        ("%%", ""),
    ]
    
    # Testes com flags
    flag_tests = [
        ("%+d", "42"),
        ("% d", "42"),
        ("%05d", "42"),
        ("%-10s", '"left"'),
        ("%#x", "255"),
        ("%10.5d", "42"),
    ]
    
    # Testes mistos
    mixed_tests = [
        ("Hello %s, you are %d years old", '"John"', "25"),
        ("%+08d %s", "42", '"test"'),
        ("0x%08X", "255"),
        ("%#10.5x", "255"),
    ]

    print(colored("\nExecutando testes básicos...", "yellow"))
    for test in basic_tests:
        params = ",".join(test[1:]) if len(test) > 1 else ""
        tester.run_test(test[0] % test[1] if params else test[0], f"Basic - {test[0]}")
    
    print(colored("\nExecutando testes com flags...", "yellow"))
    for test in flag_tests:
        params = ",".join(test[1:]) if len(test) > 1 else ""
        tester.run_test(test[0] % test[1] if params else test[0], f"Flags - {test[0]}")
    
    print(colored("\nExecutando testes mistos...", "yellow"))
    for test in mixed_tests:
        format_str = test[0]
        args = test[1:]
        try:
            formatted = format_str % eval("(" + ",".join(args) + ")")
            tester.run_test(formatted, f"Mixed - {format_str}")
        except:
            print(colored(f"Erro ao formatar teste: {format_str}", "red"))
    
    tester.print_summary()

if __name__ == "__main__":
    main()
