// TODO implemente aqui uma funcao chamada "solucao"
//   0x000000000000000a <+0>:	endbr64 
//   0x000000000000000e <+4>:	add    %edi,%edi
//   0x0000000000000010 <+6>:	lea    (%rsi,%rsi,4),%eax
//   0x0000000000000013 <+9>:	add    %edi,%eax
//   0x0000000000000015 <+11>:	mov    %eax,(%rdx)
//   0x0000000000000017 <+13>:	lea    (%rsi,%rsi,2),%eax
//   0x000000000000001a <+16>:	add    %edi,%eax
//   0x000000000000001c <+18>:	retq  

int solucao(int a, int b, int *p){
    int aux;
    a = a + a;
    aux = b + 4*b;
    aux = aux + a;
    (*p) = aux;
    aux = b + 2*b;
    aux = aux + a;
    return aux;
}