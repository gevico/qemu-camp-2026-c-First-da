#include <stdio.h>

unsigned int gcd_asm(unsigned int a, unsigned int b) {
    unsigned int result;
    
    __asm__ volatile (
        "mov %1, %%eax\n\t"     // eax = a
        "mov %2, %%ebx\n\t"     // ebx = b
        "jmp .L_check\n\t"
        
        ".L_loop:\n\t"
        "   xor %%edx, %%edx\n\t"   // edx 清零，因为 div 用 edx:eax 作为被除数
        "   divl %%ebx\n\t"         // eax = eax / ebx, edx = eax % ebx
        "   mov %%ebx, %%eax\n\t"   // a = b
        "   mov %%edx, %%ebx\n\t"   // b = 余数
        
        ".L_check:\n\t"
        "   test %%ebx, %%ebx\n\t"  // 判断 b 是否为 0
        "   jne .L_loop\n\t"
        
        "mov %%eax, %0"
        : "=r" (result)
        : "r" (a), "r" (b)
        : "eax", "ebx", "edx", "cc"
    );
    
    return result;
}

int main(int argc, char* argv[]) {
    printf("%d\n", gcd_asm(12, 8));
    printf("%d\n", gcd_asm(7, 5));
    return 0;
}