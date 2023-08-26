#include <stdio.h>

// Questao 03
// Implemente aqui uma funcao chamada ex3_solucao
// gcc -Og -g -fno-stack-protector solucao.c q3.o -lsystemd -lm -o q3`

//   0x000000000000011d <+0>:	endbr64 
//   0x0000000000000121 <+4>:	movzwl (%rdx),%ecx
//   0x0000000000000124 <+7>:	movzwl (%rsi),%eax
//   0x0000000000000127 <+10>:	lea    (%rax,%rax,4),%eax
//   0x000000000000012a <+13>:	lea    (%rax,%rcx,8),%eax
//   0x000000000000012d <+16>:	mov    %ax,(%rdi)
//   0x0000000000000130 <+19>:	movzwl (%rdx),%eax
//   0x0000000000000133 <+22>:	lea    0x2(%rax,%rax,2),%eax
//   0x0000000000000137 <+26>:	mov    %ax,(%rsi)
//   0x000000000000013a <+29>:	addw   $0x35,(%rdx)
//   0x000000000000013e <+33>:	retq   

void ex3_solucao(short *a, short *b, int *c){
    (*a) = 5*(*b) + 8*(*c);
    (*b) = 2 + (*c) + (*c)*2;
    (*c) += 53;
}