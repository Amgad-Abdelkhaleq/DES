#include <iostream>
#include<string>
#include<cstdlib>
#include <stdlib.h>
#include <sstream>
#include <algorithm>
using namespace std;
string keys[16];
int Initial_P[64]={58, 50, 42, 34, 26, 18, 10, 2,60, 52, 44, 36, 28, 20, 12, 4,62, 54, 46, 38, 30, 22, 14, 6,64, 56, 48, 40, 32, 24, 16, 8,57, 49, 41, 33, 25, 17, 9, 1,59, 51, 43, 35, 27, 19, 11, 3,61, 53, 45, 37, 29, 21, 13, 5,63, 55, 47, 39, 31, 23, 15, 7};
int Invers_IP[64]= {40,8,48,16,56,24,64,32,39,7,47,15,55,23,63,31,38,6,46,14,54,22,62,30,37,5,45,13,53,21,61,29,36,4,44,12,52,20,60,28,35,3,43,11,51,19,59,27,34,2,42,10,50,18,58,26,33,1,41,9,49,17,57,25 };
int e_table[48]={32, 1, 2, 3, 4, 5, 4, 5, 6, 7, 8, 9, 8,9, 10, 11, 12, 13, 12, 13, 14, 15, 16, 17, 16, 17, 18, 19, 20, 21, 20, 21, 22, 23, 24, 25, 24, 25, 26, 27, 28, 29, 28, 29, 30, 31, 32, 1};
int s_table[32]={16, 7, 20, 21, 29, 12, 28, 17, 1, 15, 23, 26, 5, 18, 31, 10, 2, 8, 24,14, 32, 27, 3 ,9 ,19,13, 30, 6, 22, 11, 4, 25};
int PC1[56]= { 57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36, 63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4 };
int PC2[48]= { 14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10, 23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2, 41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32 };
int Rotations[16]= { 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1 };
int tables [8][4][16]= {
{
{14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
 
{0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
 
{4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
 
{15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13},
},
{
{15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},
 
{3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
 
{0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
 
{13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9},
},
{
 
{10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
 
{13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
 
{13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
 
{1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12},
 
},
 
{
 
{7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
 
{13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
 
{10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
 
{3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14},
 
},
 
{
 
{2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
 
{14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},
 
{4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
 
{11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3},
 
},
 
{
 
{12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},
 
{10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
 
{9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},
 
{4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13},
 
},
 
{
 
{4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},
 
{13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
 
{1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
 
{6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12},
 
},
 
{
 
{13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},
 
{1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
 
{7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},
 
{2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11},
 
}
 
};



int split_integers_string_with_delimter(int parsed_arr[],string input,char delimtter){
	int index=0;
	istringstream iss (input);
	string item;
	while (getline(iss, item, delimtter)){
	parsed_arr[index]= stoi(item, nullptr, 10);
	index++;
	}
	return index;
}

string BinToHex(string bin){
string result="";
for(int i=0;i<bin.length();i=i+4){
    string part= bin.substr(i,4);
         if (part=="0000") result+='0';
         else if (part== "0001") result+="1";
         else if (part== "0010") result+=  "2";
         else if (part=="0011") result+= "3";
         else if (part=="0100") result+=  "4";
         else if (part=="0101") result+= "5" ;
         else if (part=="0110") result+= "6" ;
         else if (part=="0111") result+= "7" ;
         else if (part=="1000") result+= "8";
         else if (part=="1001") result+= "9" ;
         else if (part=="1010") result+="A" ;
         else if (part=="1011") result+="B" ;
         else if (part=="1100") result+= "C";
         else if (part=="1101") result+= "D";
         else if (part=="1110") result+= "E" ;
         else if (part=="1111") result+=  "F";
}

return result;

}
	
string HexToBin(string hexdec) 
{ 
    long int i = 0; 
    string result="";
    while (hexdec[i]) { 
  
        switch (hexdec[i]) { 
        case '0': 
            result+= "0000"; 
            break; 
        case '1': 
            result+=  "0001"; 
            break; 
        case '2': 
            result+=  "0010"; 
            break; 
        case '3': 
            result+= "0011"; 
            break; 
        case '4': 
            result+=  "0100"; 
            break; 
        case '5': 
            result+=  "0101"; 
            break; 
        case '6': 
            result+=  "0110"; 
            break; 
        case '7': 
            result+=  "0111"; 
            break; 
        case '8': 
            result+= "1000"; 
            break; 
        case '9': 
            result+=  "1001"; 
            break; 
        case 'A': 
        case 'a': 
            result+= "1010"; 
            break; 
        case 'B': 
        case 'b': 
            result+=  "1011"; 
            break; 
        case 'C': 
        case 'c': 
            result+=  "1100"; 
            break; 
        case 'D': 
        case 'd': 
            result+= "1101"; 
            break; 
        case 'E': 
        case 'e': 
            result+=  "1110"; 
            break; 
        case 'F': 
        case 'f': 
            result+=  "1111"; 
            break; 
        default: 
            cout << "\nInvalid hexadecimal digit "
                 << hexdec[i]; 
        } 
        i++; 
    } 
	return result;
}

int binaryToDecimal(string n) 
{ 
    string num = n; 
    int dec_value = 0; 
  
    // Initializing base value to 1, i.e 2^0 
    int base = 1; 
  
    int len = num.length(); 
    for (int i = len - 1; i >= 0; i--) { 
        if (num[i] == '1') 
            dec_value += base; 
        base = base * 2; 
    } 
  
    return dec_value; 
} 
string decToBinary(int n)
{
    string s;
    // Size of an integer is assumed to be 32 bits
    for (int i = 3; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            s+="1";
        else
            s+="0";
    }
    return s;
}

string strings_xor(string s, string t) {

string res = "";
for(int i = 0; i < s.size(); i++) {
    if(s[i] == t[i])
        res += '0';
    else
        res += '1';
}

return res;
}


string permutation_table_bin_version(string hex_text_plain, int table[], int table_ele_no){
	string p_out="";
	string bin_text_plain=HexToBin(hex_text_plain);
	for (int i = 0; i <table_ele_no ; i++)
	{
		int x=table[i];
		p_out+=bin_text_plain[x-1];
	}
	return p_out;
	
}

string permutation_table(string hex_text_plain, int table[], int table_ele_no){
	string p_out="";
	string bin_text_plain=HexToBin(hex_text_plain);
	for (int i = 0; i <table_ele_no ; i++)
	{
		int x=table[i];
		p_out+=bin_text_plain[x-1];
	}
	return BinToHex(p_out);
	
}
  

string left_circular_shift(string half_28_bit_key){
string res="";
int counter=0;
int key_len=half_28_bit_key.length();
   //char temp=half_28_bit_key[key_len-1];
	//res.insert(0,(temp+half_28_bit_key.substr(0,key_len-1)));
      char temp=half_28_bit_key[0];
	res.insert(0,(half_28_bit_key.substr(1,key_len-1))+temp);
	return res;
} 

void key_gen(string output_keys[],string input_64bit_bin){
	string pc1_out_56=permutation_table_bin_version(BinToHex(input_64bit_bin),PC1,56); //performe PC1
	string	pc1_first_half=pc1_out_56.substr(0,28),pc1_second_half=pc1_out_56.substr(28,28); //saperate pc1_out to 2 halves
	int no_of_shifts;
	for (int i = 0; i < 16; i++)
	{
		  no_of_shifts=Rotations[i]; //check rotaions number
		if(no_of_shifts==1){  //performe shift on the two halves
			pc1_first_half=left_circular_shift(pc1_first_half);
			pc1_second_half=left_circular_shift(pc1_second_half);
		}
		else if(no_of_shifts==2){
		pc1_first_half=left_circular_shift( left_circular_shift(pc1_first_half) );
		pc1_second_half=left_circular_shift( left_circular_shift(pc1_second_half) );
		}
		output_keys[i]=permutation_table_bin_version(BinToHex((pc1_first_half+pc1_second_half)),PC2,48); //combine and performe PC2
	}
}

	class s_box{
public:
	string six_bit_bin_input;
	string six_bit_bin_output;
	int table [4][16];
 
void set_table(int t [4][16]) { 
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j  < 16; j ++)
			{
				table[i][j]=t[i][j];
			}
		}
	}
 
string Sbox_cipher(string bin_input){
	  six_bit_bin_input=bin_input;
	  string s=bin_input.substr(0,1);
	  s=s+bin_input.substr(bin_input.length()-1,1);
	  int table_row_index=binaryToDecimal(s);
	  s=bin_input.substr(1,bin_input.length()-2);
	  int table_col_index=binaryToDecimal(s);
	   six_bit_bin_output=decToBinary(table[table_row_index][table_col_index]); 
	  return six_bit_bin_output;
}
 
 
};

s_box s_boxes[8];

string des_func(string f_input,string key_for_the_round_hex){ //ip hex_f_input,hex_key,op in binary
string  f_out, e_table_output_value,s_box_result_bin,xor_result_in_bin,s_table_input_value; 
int counter=0;
e_table_output_value=permutation_table(f_input,e_table,48);
// 2nd step get key_for_the_round_hex and xor with e_table_output_value
// xor operation here in hex
xor_result_in_bin= strings_xor(HexToBin(e_table_output_value),HexToBin(key_for_the_round_hex));
//3rd step s-box
for (int i = 0; (i < 8 && counter <xor_result_in_bin.length()); i++)
{
		s_box_result_bin+=s_boxes[i].Sbox_cipher(xor_result_in_bin.substr(counter,6));
		 counter=counter+6;
}
//4th step s_table
s_table_input_value=BinToHex(s_box_result_bin);
f_out=permutation_table_bin_version(s_table_input_value,s_table,32);
return f_out;
}

string des_round(string round_input_bin, string round_key_hex){// return binary
	string R_old,L_old,f_out,L_new,R_new;
	L_old=round_input_bin.substr(0,32);
	R_old=round_input_bin.substr(32,32);
	f_out=des_func(BinToHex(R_old),round_key_hex);
	R_new= strings_xor(f_out,L_old);
	L_new=R_old;
	return (L_new+R_new);
}

string des_encryption(string general_input_hex){
	string IP_out_bin=permutation_table_bin_version(general_input_hex,Initial_P,64);
	string rounds_results[16];
	for (int i = 0; i < 16; i++)
	{
	if(i==0) rounds_results[i]=des_round(IP_out_bin,BinToHex(keys[i]));
	else rounds_results[i]=des_round(rounds_results[i-1],BinToHex(keys[i])); 
	}
	string swap=rounds_results[15].substr(32,32)+rounds_results[15].substr(0,32);
	string cipherd_text=permutation_table_bin_version(BinToHex(swap),Invers_IP,64);

	return BinToHex(cipherd_text);
}


int main(){
string key_input,general_textplain,repetetions_str;
for (int i = 0; i < 8; i++) { s_boxes[i].set_table(tables[i]); }
int no_of_repetetions;
string res;
getline(cin,key_input);
getline (cin,general_textplain);
getline(cin,repetetions_str);
no_of_repetetions=int(atof(repetetions_str.c_str()));
key_gen(keys,HexToBin(key_input));
for (int i = 0; i <no_of_repetetions; i++)
{
 res=des_encryption(general_textplain);
 general_textplain=res;
}
if(no_of_repetetions)cout<<res;
else cout<<general_textplain;
return 0;
}