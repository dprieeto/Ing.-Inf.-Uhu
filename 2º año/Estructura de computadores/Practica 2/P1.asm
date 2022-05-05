.MODEL SMALL
.DATA
    CADENA_BINARIA DB 5, 0, 0,0,0,0,0 
    CADENA_AUX DB 5, 0, 0,0,0,0,0
    VECTOR_PESO DB 8,4,2,1
    VALOR_EQUIVALENTE_DECIMAL DB 0
    VALOR_EQUIVALENTE_CA1 DB 0 
    VALOR_EQUIVALENTE_SM DB 0
    SIGNO DB '+'

.CODE
start:
    ;Inicializar el puntero DS
    MOV AX, SEG CADENA_BINARIA
    MOV DS, AX  
    
    ;Introducir por teclado
    MOV DX, offset CADENA_BINARIA
    MOV AH, 0Ah
    INT 21h
    
    ;Restar codigo ASCII
    SUB CADENA_BINARIA[2], 48
    SUB CADENA_BINARIA[3], 48
    SUB CADENA_BINARIA[4], 48
    SUB CADENA_BINARIA[5], 48 
    
    ;Binario decimal
    MOV AX, 0
    MOV BX, 0
    
    MOV AL, CADENA_BINARIA[2]
    MUL VECTOR_PESO[0]
    ADD BX, AX
    
    MOV AL, CADENA_BINARIA[3]
    MUL VECTOR_PESO[1]
    ADD BX, AX
    
    MOV AL, CADENA_BINARIA[4]
    MUL VECTOR_PESO[2]
    ADD BX, AX
    
    MOV AL, CADENA_BINARIA[5]
    MUL VECTOR_PESO[3]
    ADD BX, AX
    
    MOV VALOR_EQUIVALENTE_DECIMAL, BL
    
    ;Complemento a uno
    MOV AX, 0 
    MOV BX, 0   
    
    MOV AL, CADENA_BINARIA[3]
    MOV CADENA_AUX[3], AL
    MOV AL, CADENA_BINARIA[4]
    MOV CADENA_AUX[4], AL
    MOV AL, CADENA_BINARIA[5]
    MOV CADENA_AUX[5], AL
 
    
    CMP CADENA_BINARIA[2], 1
    JZ NEGATIVO          ;Si se cumple, se ejecuta
    JMP CONTINUAR
    
     
    
    NEGATIVO: 
    ;Se invierte y se suma uno
    MOV AL, CADENA_BINARIA[3]
    NOT AL ;1 --> 0
    AND AL, 1
    MOV CADENA_AUX[3], AL
    
    MOV AL, CADENA_BINARIA[4]
    NOT AL
    AND AL, 1
    MOV CADENA_AUX[4], AL
    
    MOV AL, CADENA_BINARIA[5]
    NOT AL
    AND AL, 1
    MOV CADENA_AUX[5], AL
    
    MOV SIGNO, '-'    
                  
    CONTINUAR: 
    MOV AL, CADENA_AUX[3]
    MUL VECTOR_PESO[1]
    ADD BX, AX
    
    MOV AL, CADENA_AUX[4]
    MUL VECTOR_PESO[2]
    ADD BX, AX
    
    MOV AL, CADENA_AUX[5]
    MUL VECTOR_PESO[3]
    ADD BX, AX 
    
    MOV VALOR_EQUIVALENTE_CA1, BL
    
    ;Signo-Magnitud
    MOV AX, 0
    MOV BX, 0
    
    MOV AL, CADENA_BINARIA[3]
    MUL VECTOR_PESO[1] 
    ADD BX, AX 
    
    MOV AL, CADENA_BINARIA[4]
    MUL VECTOR_PESO[2]
    ADD BX, AX
    
    MOV AL, CADENA_BINARIA[5]
    MUL VECTOR_PESO[3]
    ADD BX, AX
    
    MOV VALOR_EQUIVALENTE_SM, BL
    
    ;Mostrar por pantalla
    MOV AX, 0B800h
    MOV ES, AX      ;Introducimos en ES la direccion de memoria de video
    
    MOV AL, 03h
    MOV AH, 00h   ;Limpia pantalla
    INT 10h
    
    ;Representacion binario en decimal: 
    MOV AL, VALOR_EQUIVALENTE_DECIMAL 
    MOV CL, 10
    DIV CL       ;AX/CL --> Cociente = AL  Resto = H    
    
    MOV CH, 00001111b; Fondo negro y letras blancas
    
    MOV CL, 'B'
    MOV ES:[0], CX
    MOV CL, 'I'
    MOV ES:[2], CX
    MOV CL, 'N'
    MOV ES:[4], CX
    MOV CL, ':'
    MOV ES:[6], CX 

    ADD AL, 48
    MOV ES:[8], AL
    MOV ES:[9], CH 
    ADD AH, 48
    MOV ES:[10], AH
    MOV ES:[11], CH
    
    ;Representacion signo-magnitud
    MOV AH, 00001111b 
     
    MOV AL, 'S'
    MOV ES:[160], AX
    MOV AL, 'M'
    MOV ES:[162], AX
    MOV AL, ':'
    MOV ES:[164], AX
    MOV AL, SIGNO
    MOV ES:[168], AX
    MOV AL, VALOR_EQUIVALENTE_SM
    ADD AL, 48
    MOV ES:[170], AX
    
    
    ;Mostrar complemento a 1
    MOV AH, 00001111b
    MOV AL, 'C'
    MOV ES:[320], AX
    MOV AL, '1'
    MOV ES:[322], AX
    MOV AL, ':'
    MOV ES:[324], AX
    MOV AL, SIGNO
    MOV ES:[328], AX
    MOV AL, VALOR_EQUIVALENTE_CA1
    ADD AL, 48
    MOV ES:[330], AX 
    

mov ax, 4c00h
int 21h  

end start
