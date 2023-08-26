// Questao 04
// Implemente aqui uma funcao chamada ex4_solucao
//   0x000000000000011d <+0>:	endbr64 
//   0x0000000000000121 <+4>:	mov    %edx,%r11d
//   0x0000000000000124 <+7>:	movl   $0x0,(%rcx)
//   0x000000000000012a <+13>:	movl   $0x0,(%r8)
//   0x0000000000000131 <+20>:	mov    $0x0,%r9d
//   0x0000000000000137 <+26>:	jmp    0x13d <ex4+32>
//   0x0000000000000139 <+28>:	add    $0x1,%r9d
//   0x000000000000013d <+32>:	cmp    %esi,%r9d
//   0x0000000000000140 <+35>:	jge    0x163 <ex4+70>
//   0x0000000000000142 <+37>:	movslq %r9d,%rax
//   0x0000000000000145 <+40>:	lea    (%rdi,%rax,4),%r10
//   0x0000000000000149 <+44>:	mov    (%r10),%eax
//   0x000000000000014c <+47>:	cltd   
//   0x000000000000014d <+48>:	idiv   %r11d
//   0x0000000000000150 <+51>:	test   %edx,%edx
//   0x0000000000000152 <+53>:	jne    0x139 <ex4+28>
//   0x0000000000000154 <+55>:	mov    (%rcx),%eax
//   0x0000000000000156 <+57>:	add    $0x1,%eax
//   0x0000000000000159 <+60>:	mov    %eax,(%rcx)
//   0x000000000000015b <+62>:	mov    (%r10),%eax
//   0x000000000000015e <+65>:	add    %eax,(%r8)
//   0x0000000000000161 <+68>:	jmp    0x139 <ex4+28>
//   0x0000000000000163 <+70>:	retq   

void ex4_solucao(int *vetor, int n, int divisor, int *divisiveis, int *soma){
    (*soma) = 0;
    (*divisiveis) = 0;
    for (int i = 0; i < n; i++){
        if ((vetor[i] % divisor) == 0){
            (*divisiveis) = (*divisiveis) + 1;
            (*soma) = (*soma) + vetor[i];
        }
    }
}