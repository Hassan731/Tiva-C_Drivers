//BIT_CAL.h
#ifndef bit_cal //header file guard
#define bit_cal
#define set_bit(var,bit_no) ((var)|=(1<<(bit_no)))  //var=var|(1<<bit_no)
#define clear_bit(var,bit_no) ((var)&=(~(1<<(bit_no)))) //var=var &~(1<<bit_no)
#define tog_bit(var,bit_no) ((var)^=(1<<(bit_no)))	//var=var^(1<<bit_no)
#define check_bit(var,bit_no) ((var)>>(bit_no)&(1))	//shift var by bit_no then & 1
#define assign_bit(var,bit_no,value)  do{if(value==1) set_bit(var,bit_no); \
                                          else clear_bit(var,bit_no);}while(0)
#define output_byte(var)	(var)=255
#define input_byte(var)		(var)=0
#define ass_byte(var,value)  var=value
#endif
