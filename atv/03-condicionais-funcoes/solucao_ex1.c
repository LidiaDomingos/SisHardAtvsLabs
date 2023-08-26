/* Implementar função solucao_ex1 */
//   Dump of assembler code for function ex1:
//   0x000 <+0>:  endbr64
//   0x004 <+4>:  lea    (%rdi,%rsi,1),%rax --> %rax = %rdi + 1*%rsi
//   0x008 <+8>:  lea    (%rax,%rdx,4),%rcx --> %rcx = %rax + 4*%rdx
//   0x00c <+12>: imul   %rdi,%rdi          --> %rdi = %rdi * %rdi
//   0x010 <+16>: lea    (%rdi,%rsi,2),%rax --> %rax = %rdi + 2*%rsi
//   0x014 <+20>: add    %rax,%rdx          --> %rdx = %rdx + %rax 
//   0x017 <+23>: cmp    %rdx,%rcx          --> %rcx >= %rdx
//   0x01a <+26>: setge  %al                --> se a condição de cima for vdd, seta 1
//   0x01d <+29>: movzbl %al,%eax           -->%eax = %al
//   0x020 <+32>: ret

int solucao_ex1(long arg_rdi, long arg_rsi, long arg_rdx){
    long arg_rax = arg_rdi + 1*arg_rsi;
    long arg_rcx = arg_rax + 4*arg_rdx;
    arg_rdi = arg_rdi * arg_rdi;
    arg_rax = arg_rdi + 2*arg_rsi;
    arg_rdx = arg_rdx + arg_rax;
    if (arg_rcx>=arg_rdx){
        return 1;
    }
    return 0;
}

