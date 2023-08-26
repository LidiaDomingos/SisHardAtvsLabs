long vezes2(long a);

/* Implementar função solucao_ex2 */
//Dump of assembler code for function ex2:
//   0x01132 <+0>:    endbr64
//   0x01136 <+4>:    push   %rbx            -->
//   0x01137 <+5>:    mov    %rdi,%rbx       --> %rbx = %rdi
//   0x0113a <+8>:    mov    %rsi,%rdi       --> %rdi = %rsi 
//   0x0113d <+11>:   call   0x1129 <vezes2> --> vezes2()
//   0x01142 <+16>:   cmp    %rbx,%rax       --> %rax <= %rbx
//   0x01145 <+19>:   jle    0x114a <ex2+24> 
//   0x01147 <+21>:   add    %rbx,%rbx
//   0x0114a <+24>:   add    %rbx,%rax
//   0x0114d <+27>:   pop    %rbx
//   0x0114e <+28>:   ret 

long solucao_ex2(long rdi, long rsi){
    long rax;
    long arg_rbx = rdi;
    long arg_rdi = rsi;
    rax = vezes2(arg_rdi);
    if (rax <= arg_rbx){
        rax = rax+ arg_rbx; 
        return rax;
    }
    arg_rbx = arg_rbx + arg_rbx;
    rax = rax + arg_rbx;
    return rax;
}