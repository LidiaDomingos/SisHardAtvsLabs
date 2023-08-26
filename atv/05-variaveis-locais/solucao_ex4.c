//Dump of assembler code for function ex4:
//   0x00000000000012ae <+0>:	endbr64 
//   0x00000000000012b2 <+4>:	push   %rbx       
//   0x00000000000012b3 <+5>:	sub    $0x10,%rsp             --> variável local
//   0x00000000000012b7 <+9>:	mov    %edi,%ebx              --> isso vai pro scan
//   0x00000000000012b9 <+11>:	lea    0x8(%rsp),%rdx         --> p2 = &a
//   0x00000000000012be <+16>:	lea    0xc(%rsp),%rsi         --> p1 = &b esse ve
//   0x00000000000012c3 <+21>:	lea    0x1d3a(%rip),%rdi        # 0x3004
//   0x00000000000012ca <+28>:	mov    $0x0,%eax              --> 
//   0x00000000000012cf <+33>:	callq  0x1190 <__isoc99_scanf@plt>
//   0x00000000000012d4 <+38>:	mov    0x8(%rsp),%edx         --> edx = p2 
//   0x00000000000012d8 <+42>:	mov    0xc(%rsp),%eax         --> eax = p1
//   0x00000000000012dc <+46>:	lea    (%rax,%rdx,2),%eax     --> eax = rax + 2rdx
//   0x00000000000012df <+49>:	add    %ebx,%eax              --> eax = eax + ebx 
//   0x00000000000012e1 <+51>:	add    $0x10,%rsp             
//   0x00000000000012e5 <+55>:	pop    %rbx
//   0x00000000000012e6 <+56>:	retq   
//End of assembler dump.

int ex4_solucao(int d) {
    // implemente sua resposta aqui.
    // TODO: conserte valor de retorno e argumentos, se for necessário
    int p1, p2;

    scanf("%d %d", &p1, &p2);
    int eax = 0;
    int edx = p2;
    eax = p1; 
    eax = eax + 2*edx;
    eax = eax + d;
    return eax;
}