bits 64                    ; x86-64 assembly
section .text              ; Code section
global memset              ; Export memset

                           ;                 rdi     rsi (sil)      rdx
memset:                    ; void *memset(void* dest, int char, size_t count);
    mov rcx, 0             ; Make rcx (iterator) start at 0

.loop:                     ; Copy char on dest char until count chars copied
    cmp rcx, rdx           ; Compare iterator with count
    je .end                ; If same (count bytes replaced) jump to .end
    mov byte[rdi+rcx], sil ; Else move char to dest+iterator
    inc rcx                ; And increment iterator (advance in dest)
    jmp .loop              ; And jump to .loop (recursive)

.end:
    mov rax, rdi           ; Move dest to rax
    ret                    ; End program correctly (rax has dest)