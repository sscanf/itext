//Proceso de retardo de 1ms.
//Está calculado para un clock interno de 4915 Hz
//
//El calculo es el siguiente:
//
//delay = (ClockInterno / 13)

#define DELAY 4915/13

void delay_ms (char delay)
{
asm{
delay_ms:	                            //5 cycles for JSR ext
                psha                    //2 Stack Accumulator
                pshx                    //2 Stack Index Register X
                pshh                    //2 Stack Index Register H
                tax                     //1 Save Accumulator in Index X
                tpa                     //1 Get Condition Code reg into Acc
                psha                    //2 Stack Condition Code reg
                txa                     //1 Restore Accumulator

DelaymS3010:

DelaymS3020:    ldhx    #DELAY          //  3 Load delay into H:X
DelaymS3030:    aix     #-1             //  2 Decrement delay
                sta     0XFFFF			//  $FFFF=COPCTL ,  4 Kick the WDOG so the part doesn't reset
                nop                     //  1 Burn 1 cycle
                cphx    #0              //  3 Done yet?
                bne     DelaymS3030     //  3 Branch if not done
                                        //  3+(13*378)=4915
                nop                     // 1 burn 1 bus cycle
                dbnza   DelaymS3010     // 3 decrement # of mS to delay
                                        //   branch if not done
                                        // Acc*(4915+4) = Acc * 4919

                pula                    //2 Unstack Condition Code register data
                tap                     //1 Restore Condition Code register
                pulh                    //2 Unstack Index Register H
                pulx                    //2 Unstack Index Register X
                pula                    //2 Unstack Accumulator

DelaymS3015:    rts                     //4 all done - return to calling routine
                                        //27 + Acc*1229
};
}