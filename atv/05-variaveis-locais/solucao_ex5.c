//Dump of assembler code for function ex5:
//   0x00000000000012ae <+0>:	endbr64 
//   0x00000000000012b2 <+4>:	push   %rbx                    
//   0x00000000000012b3 <+5>:	sub    $0x10,%rsp
//   0x00000000000012b7 <+9>:	movl   $0x1,0xc(%rsp)     -->     
//   0x00000000000012bf <+17>:	mov    $0x0,%ebx          
//   0x00000000000012c4 <+22>:	cmpl   $0x0,0xc(%rsp)
//   0x00000000000012c9 <+27>:	jle    0x12ed <ex5+63>
//   0x00000000000012cb <+29>:	lea    0xc(%rsp),%rsi
//   0x00000000000012d0 <+34>:	lea    0xd2d(%rip),%rdi        # 0x2004
//   0x00000000000012d7 <+41>:	mov    $0x0,%eax
//   0x00000000000012dc <+46>:	callq  0x1190 <__isoc99_scanf@plt>
//   0x00000000000012e1 <+51>:	mov    0xc(%rsp),%eax
//   0x00000000000012e5 <+55>:	test   %eax,%eax
//   0x00000000000012e7 <+57>:	jle    0x12c4 <ex5+22>
//   0x00000000000012e9 <+59>:	add    %eax,%ebx
//   0x00000000000012eb <+61>:	jmp    0x12c4 <ex5+22>
//   0x00000000000012ed <+63>:	mov    %ebx,%eax
//   0x00000000000012ef <+65>:	add    $0x10,%rsp
//   0x00000000000012f3 <+69>:	pop    %rbx
//   0x00000000000012f4 <+70>:	retq   
//End of assembler dump.

int ex5_solucao () {
    // implemente sua resposta aqui.
    // TODO: conserte valor de retorno e argumentos, se for necessário
    int a = 1;
    int eax = 0;
    int ebx = 0;
    while (a > 0){
        scanf("%d", &a);
        eax = a;
        if ((eax&eax) > 0){
            ebx = eax + ebx; 
        }
    }
    eax = ebx;
    return eax;
}
