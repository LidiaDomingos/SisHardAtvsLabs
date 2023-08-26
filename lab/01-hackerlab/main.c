int func1(int rdi[], int rsi){
    int eax = 0;
    int edx = -1 + rsi;
    while (edx > eax){
        int rcx = 8 + rdi[edx] + edx*8;
        if ((rdi[edx] + edx*8) > rcx ){
            eax = 0;
            return eax;
        }
        eax = eax + 1;
    }
    eax = 1;
    return eax;
}

int func2(int rdi[], int esi){
    int eax = 0;
    while (eax < esi){
        int rdx = eax;
        if (rdi[esi] < 0){
            eax = 1;
            return eax;
        }
    eax = eax + 1;
    }
    eax = 0;
    return eax;
}

int func3(int rdi[],int esi){
    int edx = 0;
    int eax_soma = 0;
    while (edx < esi){
        int rcx = edx;
        eax_soma = rdi[edx] + eax_soma;
        edx = edx + 1;
    }
    return eax_soma;
}

int level9(int vetor[]){
    int ebx = 0;
    int eax;
    while (ebx <= 9){
        eax = vetor[ebx];
        int rsi = eax + 8*ebx;
        eax = 0;
        ebx = ebx + 1;
    }
    int rsi = 10;
    int eax_soma = func3(vetor, rsi);
    if (eax_soma <= 10){
        eax_soma = 0;
        return eax;
    }
    eax = func2(vetor, rsi);
    if (eax == 0){
        return 0;
    }
    eax = func1(vetor,rsi);
    if (eax == 0){
        eax = 1;
    }
    return eax;
}
//
//int leve10(int x){
//    int *rsi;
//    int eax = 0;
//    char rcx[7] = "LIDIA";
//    long b;
//    int edx = 0;
//    scanf("%d", &b);
//    eax = rcx + eax;
//    while(){
//        b = b - eax;
//        edx = edx + 1; 
//    }
//    
//
//
//}

int level5(int rdi, int rsi){
    int rax;
    int r8b;
    rax = rdi  + 4*rdi;
    rax = 81 + rax + 4*rsi;
    
    if ((rax == 20492006) == 0){
        int r8b = (rax == 20492006);
    }
    int cl = rdi != rsi; 
    int edx = 0;
    if ((r8b&cl) == 0){
        edx = 1;
        int al = (rax > 55875);
        int dl = (rdi < -14);
        rax = rax&edx;
        return rax; 
    }
    int al = (rax > 55875);
    int dl = (rdi < -14);
    rax = rax&edx;
    return rax;
}