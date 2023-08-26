/* Implemente aqui sua versão em C da função ex3
 * presente no arquivo ex3.o
 * 
 * Chame sua função de ex3_solucao */
//Dump of assembler code for function ex3:
//   0x000 <+0>:  endbr64 
//   0x004 <+4>:  mov    $0x0,%ecx      --> rcx = 0
//   0x009 <+9>:  mov    $0x0,%r8d      --> r8d = 0
//   0x00f <+15>: jmp    0x15 <ex3+21>  --> pula pra 21
//   0x011 <+17>: add    $0x1,%rcx      --> rcx = rcx + 1
//   0x015 <+21>: cmp    %rdi,%rcx      --> rcx - rdi >= 0
//   0x018 <+24>: jge    0x2c <ex3+44>  --> pula pra 44
//   0x01a <+26>: mov    %rcx,%rax      --> rax =rc
//   0x01d <+29>: cqto                  -->
//   0x01f <+31>: idiv   %rsi           --> rax = rax/rsi e resto em rdx
//   0x022 <+34>: test   %rdx,%rdx      --> rdx&rdx != 0
//   0x025 <+37>: jne    0x11 <ex3+17>  --> pula pra 17
//   0x027 <+39>: add    %rcx,%r8       -->r8 = r8 + rcx
//   0x02a <+42>: jmp    0x11 <ex3+17>  -->
//   0x02c <+44>: mov    %r8,%rax       --> rax = r8
//   0x02f <+47>: ret

long ex3_solucao(long rdi, long rsi){
    long rcx = 0;
    long r8 = 0;
    long rax, rdx;
    while (rcx<rdi){
        rax = rcx;
        rax = rcx/rsi;
        rdx = rcx%rsi;
        if (rdx == 0){
            r8 = r8 + rcx;
        }
        rcx = rcx + 1;
    }
    rax = r8;
    return rax;
}