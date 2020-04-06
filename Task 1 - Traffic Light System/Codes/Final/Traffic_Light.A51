     	TABLE_RIGHT EQU 100H			; start address of look-up Table
		RED BIT P1.6
		GREEN BIT P1.5
		BTN_FREQ EQU P0.0
		BTN_SEC60 EQU P0.1
		LEFT_SEGMENT EQU P3
		RIGHT_SEGMENT EQU P2
		
		ORG 0					;tells the compiler all subsequent code starting at address 0
		CLR BTN_FREQ
		CALL ON
		MOV DPTR, #TABLE_RIGHT

		// Check Max counter
		JB BTN_SEC60, SET_MAX60

SET_MAX30:	MOV A, #2				;max left segment
			MOV R1, A
			MOVC A, @A+DPTR
			MOV LEFT_SEGMENT, A
			MOV A, #3				;MSB Tracker, Max Left Segment + 1
			MOV R2, A
			JMP MAIN

SET_MAX60:	MOV A, #5				;max left segment
			MOV R1, A
			MOVC A, @A+DPTR
			MOV LEFT_SEGMENT, A	
			MOV A, #6				;MSB Tracker, Max Left Segment + 1
			MOV R2, A
			JMP MAIN

MAIN:	MOV A, #9
		MOV R0, A
		
LOOP3:	MOVC A, @A+DPTR			; location in the look-up Table
		MOV RIGHT_SEGMENT, A	; write to the 7-segment
		DEC R0
		MOV A, R0
		ACALL DELAY_1s
		CJNE R0, #0H, LOOP3		; check the number
		DEC R2

		MOVC A, @A+DPTR
		MOV RIGHT_SEGMENT, A
		ACALL DELAY_1s
		CJNE R2, #0, LCONT
		CALL REST
		JMP MAIN

LCONT:	DEC R1
		MOV A, R1
		MOVC A, @A+DPTR
		MOV LEFT_SEGMENT, A

		JMP MAIN

REST:	CALL TOG
		JNB BTN_SEC60, SET_MAX30
		JB BTN_SEC60, SET_MAX60
		RET

ON:		SETB GREEN
		CLR RED
		RET
		
OFF:	CLR GREEN
		SETB RED
		RET

TOG:	CPL GREEN
		CPL RED
		RET
			
		;look up table for right seven segment common cathode
        ORG TABLE_RIGHT
        DB 3FH,06H,5BH,4FH,66H,6DH,7DH,07H,7FH,6FH

DELAY_1s:  	MOV R4, #8
			JB BTN_FREQ, INC_FREQ
			MOV R5, #0
			MOV R6, #0
			
LOOP2:		DJNZ R6, LOOP2
			DJNZ R5, LOOP2
			DJNZ R4, LOOP2
			RET

INC_FREQ:	MOV R4, #6			   ; delay 1s ---> (256 * 256 * 24 * 8 + 24) / 12000000
			RET

			END