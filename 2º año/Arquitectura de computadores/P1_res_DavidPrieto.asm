.MODEL SMALL
.CODE
     org 100h
Programa_Int:
     JMP Reside
contador_int db 0

Rutina_Servicio PROC
    CLI
    INC contador_int
    CMP contador_int, 1   ; cuando el contador = 1, detiene todo y espera a que se pulse una tecla  -> T_ejecuci�n = 0.055 sg
    JNE fin                           ; si contador no es = 2, sale de la Rutina con IRET
    
    
    MOV AH, 4ch
    INT 21h               ; y finalmente se provoca esta interrupci�n para poner salir a MS-DOS
fin:
   STI
   IRET
ENDP

Reside: ;etiqueta para determinar la direcci�n siguiente a la �ltima de la rutina  que debe quedar residente
  MOV DX, offset Rutina_Servicio
  MOV AX, 0
  MOV ES, AX
  MOV SI, 1ch*4
  CLI
  MOV ES:[SI], DX          ; en la direcci�n de memoria es:[si] se deja el offset de la Rutina de Servicio
  MOV ES:[SI+2], CS     ; en la direcci�n de memoria es:[si+2] se deja el valor del segmento de c�digo CS
  STI
  MOV DX, offset Reside    ; 
  INT 27h                             ; esta interrupci�n deja residente todo el c�digo que hay desde 'Reside' hacia arriba
END Programa_Int