bits 64                  ; x86-64 assembly
section .text            ; Code section
global strlen            ; Export strlen

                         ;                     rdi
strlen:                  ; size_t strlen(const char *str)
    mov rax, 0			 ; Make rax (iterator & return value) start at 0

.loop:                   ; Increment iterator for each str char until '\0'
    cmp byte[rdi+rax], 0 ; Compare current char (byte at str+iterator) with 0 ('\0')
    je .end				 ; If same (reached end of str) jump to .end
	inc rax              ; Else increment iterator (advance in str)
    jmp .loop            ; And jump to .loop (recursive)

.end:
    ret                  ; End program correctly (rax has iterator = str length)