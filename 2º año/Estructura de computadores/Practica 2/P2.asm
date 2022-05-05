.MODEL SMALL
.CODE
	org 100h
Programa_Int:
	JMP Reside  
	;DECLARAMOS VARIABLES
	RELOJ dB '00:00'
	CONTADOR DB 0

Rutina_Servicio PROC
	
	CLI      
	;salva el contenido de los registros implicados en la rutina
	
        
    INC CONTADOR ;PRIMERO LO INCREMENTO 

	CMP CONTADOR,18 ;compara si vle 18 sino finaliza
	     
	JE VALE18       ;contador=18
    JMP FIN 
         
        VALE18:
    
    MOV CONTADOR,0   
      
    
    MOV AX,0B800h                                                                                                
    MOV ES,AX   
     
    MOV  AH,00001111b    ;texto blanco y fondo negro
    MOV SI,0             ;asigna a SI el valor 0
    MOV DI,148           ;y a Di 148  /148 es donde vamos empezar a colocar el reloj en la pantalla
                         ;xk la pantalla tiene x caracteres que van 2 en 2
    
  
        RELOJ2:
    MOV AL,RELOJ[SI]
    MOV ES:[DI],AX
    ADD DI,2
    ADD SI,1 
       
    CMP SI,4
    JBE RELOJ2
     

     

;controlamos el reloj
    CMP RELOJ[4],'9'          ;segundo
    JNE PRINCIPIO             ;salto indirecto

	MOV RELOJ[4],'0'
    INC RELOJ[3]
	
     
     	
    CMP RELOJ[3],'6'        ;minuto
    JNE FIN
	    
	MOV RELOJ[3],'0'
	INC RELOJ[1]
	
      
	CMP RELOJ[1],'9'      ;minutos
	JNE FIN
      	
    MOV RELOJ[1],'0'  
	INC RELOJ[0]
	
    	 
         PRINCIPIO: 

	INC RELOJ[4]
         
         FIN :
         
         
     STI        ;activa las interrupciones
	 IRET       ; Recupera el valor de los registros implicados en la rutina
ENDP        ;termina el procedimiento
      
        
                     


Reside: ;etiqueta para determinar la dirección siguiente a la última de la rutina
        ;que debe quedar residente
	MOV DX, offset Rutina_Servicio   ;copia la direccion de Rutina_Servicio a dx
	MOV AX, 0
	MOV ES, AX
	MOV SI, 1Ch*4 ;para saber donde se encuentra la rutina *4(todas ocupan 4 pos de memo)
	CLI
	MOV ES:[SI], DX
	MOV ES:[SI+2], CS
	STI
	MOV DX, offset Reside; para terminar y dejar residente el codigo
	INT 27h
END Programa_Int