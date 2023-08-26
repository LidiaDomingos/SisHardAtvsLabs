/* Implementar função solucao_ex3 */
//Dump of assembler code for function ex3:
//   0x0000000000000000 <+0>:	endbr64 
//   0x0000000000000004 <+4>:	cmp    %rsi,%rdi --> %rdi < %rsi
//   0x0000000000000007 <+7>:	setl   %al
//   0x000000000000000a <+10>:	movzbl %al,%eax --> return 1
//   0x000000000000000d <+13>:	mov    %eax,(%rdx) 
//   0x000000000000000f <+15>:	sete   %al
//   0x0000000000000012 <+18>:	movzbl %al,%eax
//   0x0000000000000015 <+21>:	mov    %eax,(%rcx)
//   0x0000000000000017 <+23>:	setg   %al
//   0x000000000000001a <+26>:	movzbl %al,%eax
//   0x000000000000001d <+29>:	mov    %eax,(%r8)
//   0x0000000000000020 <+32>:	retq   

void solucao_ex3(long rdi, long rsi, int *p1, int *p2, int *p3){
    (*p1) = (rdi < rsi);
    (*p2) = (rdi == rsi);
    (*p3) = (rdi > rsi);
}