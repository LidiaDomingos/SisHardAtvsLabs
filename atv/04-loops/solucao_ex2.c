
/* Implemente aqui sua versão em C da função soma_n
 * presente no arquivo ex2.o
 *
 * Chame sua função de soma_n_solucao */

//Dump of assembler code for function soma_n:
//  0x000 <+0>:  endbr64 
//  0x004 <+4>:  mov    $0x0,%eax        --> eax = 0
//  0x009 <+9>:  mov    $0x0,%edx        --> edx = 0
//  0x00e <+14>: cmp    %edi,%eax        --> eax - edi >= 0 
//  0x010 <+16>: jge    0x1d <soma_n+29> --> se for vdd, pula pra 29
//  0x012 <+18>: movslq %eax,%rcx        --> rcx = eax
//  0x015 <+21>: add    %rcx,%rdx        --> rdx = rdx + rcx
//  0x018 <+24>: add    $0x1,%eax        --> eax = eax + 1
//  0x01b <+27>: jmp    0xe <soma_n+14>  --> volta pro loop
//  0x01d <+29>: mov    %rdx,%rax        --> rax = rdx
//  0x020 <+32>: ret                     -->

long soma_n_solucao(int edi){
    long rax = 0;
    long rdx = 0;
    long rcx;
    while(rax < edi){
        rcx = rax;
        rdx = rdx + rcx;
        rax = rax + 1;
    }
    rax = rdx;
    return rax;
}