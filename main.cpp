#include <iostream>
#include <string>
#include<cmath>
#include <deque>
#include <bitset>
#include<bits/stdc++.h>
using namespace std;

deque<int> text_toBinary(string const& str)
{
    deque<int> binary;
    for (int i = 0; i < 16; i++)
    {
        string b = bitset<8>(str[i]).to_string();
        for (int j = 0; j < 8; j++)
        {
            binary.push_back(b[j] - 48);
        }
    }
    return binary;
}
//-------------------------------------------------------------------------------
int XOR(int num1, int num2) /// XOR between two Integers
{
    int result = 0;
    result = (num1+num2)%2;
    return result;
}
deque<int> XOR_deque(deque<int>d1, deque<int>d2) /// XOR between two Deques
{
    deque<int> result;
    int d1Size = d1.size();

    for(int i = 0 ; i < d1Size ; i++)
    {
        result.push_back((d1[i]+d2[i])%2);
    }
    return result;
}
//-------------------------------------------------------------------------------
int str_to_int(string str) ///Converts String into Integer
{
    int num = 0;
    if (str >= "0" && str <= "9")
    {
        for (int i = str.length() - 1, j = 0; i > -1 && j < str.length(); i--, j++)
        {
            num += pow(10, i) * (str[j] - 48);
        }

    }
    else if ((str >= "A" && str <= "F") || (str >= "a" && str <= "f"))
    {
        if (str == "A" || str == "a")
        {
            num = 10;
        }
        else if (str == "B" || str == "b")
        {
            num = 11;
        }
        else if (str == "C" || str == "c")
        {
            num= 12;
        }
        else if (str == "D"|| str == "d")
        {
            num = 13;
        }
        else if (str == "E"|| str == "e")
        {
            num = 14;
        }
        else if (str == "F"|| str == "f")
        {
            num = 15;
        }
    }
    return num;
}
//-------------------------------------------------------------------------------
deque<int> DecimalToBinary(int decimal, int no_of_bits)///Convert Decimal form into Binary Form by Setting the no. of bit representation
{
    //int binary = 0;
    deque<int>dq_binary;
    string str_bin = "";
    for (int i = (no_of_bits - 1); i > -1; i--)
    {
        if (decimal >= pow(2, i))
        {
            str_bin += "1";
            decimal -= pow(2, i);
        }
        else
        {
            str_bin += "0";
        }
    }
    for (int i = 0; i < no_of_bits; i++)//pushing the answer in a deque
    {
        dq_binary.push_back(str_bin[i] - 48);
    }
    //////////////////////
//        for(auto it=dq_binary.begin(); it!=dq_binary.end(); it++)//printing deque
//        {
//            cout<<"DecimalToBinary: ";
//            cout << *it << " ";
//        }
//        cout<<endl;
    //////////////////////
    return dq_binary;
}
//-------------------------------------------------------------------------------
int BinaryToDecimal(deque<int> bin)///Convert Binary Deque form into Decimal Form
{
    int decimal = 0, length = bin.size();
    for (int i = 0; i < length; i++)// 0 1 1 =3
    {
        if (bin[i] == 1)
        {
            //3   - 2-1
            decimal += pow(2, (length - i - 1));
        }
    }
    //    cout<<"decimal:"<<decimal<<endl;
    return decimal;
}
//Overriding
int BinaryToDecimal(string bin)///Convert Binary "String form" into Decimal Form
{
    int decimal = 0, length = 0;
    int int_bin = str_to_int(bin);
    while (int_bin > 0)
    {
        int_bin /= 10;
        length++;
    }
    int_bin = str_to_int(bin);
    for (int i = 0; i < length; i++)
    {
        if (int_bin % 10 == 1)
        {
            decimal += pow(2, i);
            int_bin /= 10;
        }
        else
        {
            int_bin /= 10;
            continue;
        }
    }
    return decimal;
}
//-------------------------------------------------------------------------------
string BinarytoASCII(deque<int> str) ///Converting the Binary form of strings to its ASCII Form
{
    int N = int(str.size());

    string res = "";
    deque<int> str1 ;

    for (int i = 0; i <= N; i++)
    {
        if(i%8==0 && i!=0)
        {
            int decimal_value= BinaryToDecimal(str1);
            res += char(decimal_value);

            str1.clear();
            str1.push_back(str[i]-48);
        }
        else
        {
            str1.push_back(str[i]);
        }

    }
    return res;
}
//-------------------------------------------------------------------------------
deque<int> hex_to_binary(string hex)
{
    deque<int> binary;
    deque<int> DECIMALbinary0;
    deque<int> DECIMALbinary1;
    int strDECIMAL0 = str_to_int(hex.substr(0, 1));
    int strDECIMAL1 = str_to_int(hex.substr(1, 1));

    DECIMALbinary0 = DecimalToBinary(strDECIMAL0, 4);
    DECIMALbinary1 = DecimalToBinary(strDECIMAL1, 4);

    binary.insert(binary.begin(), DECIMALbinary0.begin(), DECIMALbinary0.end());
    binary.insert(binary.end(), DECIMALbinary1.begin(), DECIMALbinary1.end());

    return binary;
}
//-------------------------------------------------------------------------------
string binToHexap(deque<int> bin)
{
    deque<int> bin1;
    string ans1 = "";
    while (bin.size()!=0)
    {
        for(int i=0;i<8 && bin.size()!=0;i++)
        {
            bin1.push_back(bin.front());
            bin.pop_front();
        }
        int n = BinaryToDecimal(bin1);
        string ans = "";
        int n1=n;
        bin1.clear();

        if(n == 0)
        {
            ans+= "0";
        }
        else
        {
            while (n != 0)
            {
                int rem = 0;
                char ch;
                rem = n % 16;
                if (rem < 10) {
                    ch = rem + 48;
                }
                else {
                    ch = rem + 55;
                }
                ans += ch;
                n = n / 16;
            }
            int i = 0, j = ans.size() - 1;
            while (i <= j)
            {
                swap(ans[i], ans[j]);
                i++;
                j--;
            }
        }
        ans1+=ans;
    }

    return ans1;
}
string binToHexa(deque<int> bin)
{
    deque<int> bin1;
    string ans1 = "";
    while (bin.size()!=0)
    {
        for(int i=0;i<8 && bin.size()!=0;i++)
        {
            bin1.push_back(bin.front());
            bin.pop_front();
        }
        int n = BinaryToDecimal(bin1);
        string ans = "";
        int n1=n;
        bin1.clear();

        if(n == 0)
        {
            ans+= "0";
        }
        else
        {
            while (n != 0)
            {
                int rem = 0;
                char ch;
                rem = n % 16;
                if (rem < 10) {
                    ch = rem + 48;
                }
                else {
                    ch = rem + 55;
                }
                ans += ch;
                n = n / 16;
            }
            int i = 0, j = ans.size() - 1;
            while (i <= j)
            {
                swap(ans[i], ans[j]);
                i++;
                j--;
            }
        }
        if((n1<=9 && n1!=0)||(ans=="A")||(ans=="B")||(ans=="C")||(ans=="D")||(ans=="E")||(ans=="F"))
        {
            ans="0"+ans;
        }
        ans1+=ans;
    }

    return ans1;
}
//-------------------------------------------------------------------------------
void printmatrix(deque< deque< deque<int> > >Matrix4x4_B)
{
    deque< deque<int> >::iterator ptr;
    deque<int>::iterator ptr1;

    for (auto ptr = Matrix4x4_B.begin(); ptr != Matrix4x4_B.end(); ptr++)//printing deque
    {
        for (auto ptr1=ptr->begin(); ptr1 != ptr->end(); ptr1++)//printing deque
        {
            for (auto it = ptr1->begin(); it !=ptr1->end(); it++)//printing deque
            {
                cout << *it << " ";
            }
            cout << "-- ";
        }
        cout << endl;
    }
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ HEX ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    for (int i = 0; i < Matrix4x4_B.size(); ++i)
    {
        cout << "                                   ";
        for (int j = 0; j <Matrix4x4_B[i].size() ; ++j)
        {
            cout<< binToHexa(Matrix4x4_B[i][j])<< " ";;
        }
        cout << endl;
    }
    cout << endl;
}
string S_Box(int row, int column)
{
    string S_table[16][16] =
            { "63", "7C", "77", "7B", "F2", "6B", "6F", "C5", "30", "01", "67", "2B", "FE", "D7", "AB", "76"
                    ,"CA", "82", "C9", "7D", "FA", "59", "47", "F0", "AD", "D4", "A2", "AF", "9C", "A4", "72", "C0"
                    ,"B7", "FD", "93", "26", "36", "3F", "F7", "CC", "34", "A5", "E5", "F1", "71", "D8", "31", "15"
                    ,"04", "C7", "23", "C3", "18", "96", "05", "9A", "07", "12", "80", "E2", "EB", "27", "B2", "75"
                    ,"09", "83", "2C", "1A", "1B", "6E", "5A", "A0", "52", "3B", "D6", "B3", "29", "E3", "2F", "84"
                    ,"53", "D1", "00", "ED", "20", "FC", "B1", "5B", "6A", "CB", "BE", "39", "4A", "4C", "58", "CF"
                    ,"D0", "EF", "AA", "FB", "43", "4D", "33", "85", "45", "F9", "02", "7F", "50", "3C", "9F", "A8"
                    ,"51", "A3", "40", "8F", "92", "9D", "38", "F5", "BC", "B6", "DA", "21", "10", "FF", "F3", "D2"
                    ,"CD", "0C", "13", "EC", "5F", "97", "44", "17", "C4", "A7", "7E", "3D", "64", "5D", "19", "73"
                    ,"60", "81", "4F", "DC", "22", "2A", "90", "88", "46", "EE", "B8", "14", "DE", "5E", "0B", "DB"
                    ,"E0", "32", "3A", "0A", "49", "06", "24", "5C", "C2", "D3", "AC", "62", "91", "95", "E4", "79"
                    ,"E7", "C8", "37", "6D", "8D", "D5", "4E", "A9", "6C", "56", "F4", "EA", "65", "7A", "AE", "08"
                    ,"BA", "78", "25", "2E", "1C", "A6", "B4", "C6", "E8", "DD", "74", "1F", "4B", "BD", "8B", "8A"
                    ,"70", "3E", "B5", "66", "48", "03", "F6", "0E", "61", "35", "57", "B9", "86", "C1", "1D", "9E"
                    ,"E1", "F8", "98", "11", "69", "D9", "8E", "94", "9B", "1E", "87", "E9", "CE", "55", "28", "DF"
                    ,"8C", "A1", "89", "0D", "BF", "E6", "42", "68", "41", "99", "2D", "0F", "B0", "54", "BB", "16" };
    string outputByte = S_table[row][column];
    return outputByte;
}
//--------------------------------------------------------------------------------------------------------------------------
deque < deque<int> > shift_left(deque < deque<int> > d, int shift_no)//Shift left in row ---> ShiftRows Sublayer SubFunction
{
    deque<int> temp;
    for (int i = 0; i < shift_no; i++)
    {
        temp = d.front();
        d.pop_front();
        d.push_back(temp);
    }
    return d;
}
deque< deque< deque<int> > >ShiftRows(deque < deque< deque<int> > >deque_2D)// ShiftRows Sublayer Function
{
    for (int i = 0; i < deque_2D.size(); i++)
    {
        deque_2D[i] = shift_left(deque_2D[i], i);
    }
    deque< deque< deque<int> > >dequeOUT = deque_2D;
    return deque_2D;
}
//--------------------------------------------------------------------------------------------------------------------------sbox's row & col
pair<int,int> SRC(deque<int> bin)
{
    pair<int, int> p;
    deque<int> v;
    string r;
    string c;
    for (int x = 0; x < 4; x++)
    {
        v.push_back(bin.front());
        bin.pop_front();
    }
    r = binToHexap(v);
    v.clear();
    for (int x = 4; x < 8; x++)
    {
        v.push_back(bin.front());
        bin.pop_front();
    }
    c = binToHexap(v);

    if (r == "A")
    {
        p.first = 10;
    }
    else if (r == "B")
    {
        p.first = 11;
    }
    else if (r == "C")
    {
        p.first = 12;
    }
    else if (r == "D")
    {
        p.first = 13;
    }
    else if (r == "E")
    {
        p.first = 14;
    }
    else if (r == "F")
    {
        p.first = 15;
    }
    else
    {
        p.first = str_to_int(r);
    }

    if (c == "A")
    {
        p.second = 10;
    }
    else if (c == "B")
    {
        p.second = 11;
    }
    else if (c == "C")
    {
        p.second = 12;
    }
    else if (c == "D")
    {
        p.second = 13;
    }
    else if (c == "E")
    {
        p.second = 14;
    }
    else if (c == "F")
    {
        p.second = 15;
    }
    else
    {
        p.second = str_to_int(c);
    }

    return p;

}
//--------------------------------------------------------------------------------------------------------------------------Key Generation
deque<int> RC(int i)
{
    if(i==1)
    {
        deque<int> d ={0,0,0,0,0,0,0,1};
        return d;
    }
    else if(i==2)
    {
        deque<int> d ={0,0,0,0,0,0,1,0};
        return d;
    }
    else if(i==3)
    {
        deque<int> d ={0,0,0,0,0,1,0,0};
        return d;
    }
    else if(i==4)
    {
        deque<int> d ={0,0,0,0,1,0,0,0};
        return d;
    }
    else if(i==5)
    {
        deque<int> d ={0,0,0,1,0,0,0,0};
        return d;
    }
    else if(i==6)
    {
        deque<int> d ={0,0,1,0,0,0,0,0};
        return d;
    }
    else if(i==7)
    {
        deque<int> d ={0,1,0,0,0,0,0,0};
        return d;
    }
    else if(i==8)
    {
        deque<int> d ={1,0,0,0,0,0,0,0};
        return d;
    }
    else if(i==9)
    {
        deque<int> d ={0,0,0,1,1,0,1,1};
        return d;
    }
    else if(i==10)
    {
        deque<int> d ={0,0,1,1,0,1,1,0};
        return d;
    }
}
deque<int> g(deque<int> word,int rc)
{
    deque<int>new_word;
    deque<int> v1;
    for (int x = 0; x < 8; x++)
    {
        word.push_back(word.front());
        word.pop_front();
    }

    for (int x = 0; x < 8; x++)
    {
        v1.push_back(word.front());
        word.pop_front();
    }

    pair<int, int> p;
    p = SRC(v1);
    string sv = S_Box(p.first, p.second);

    deque<int> v1sv;
    v1sv=hex_to_binary(sv);

    deque<int> v1f;
    v1f=XOR_deque(v1sv,RC(rc));

    for(int i=0;i<8;i++)
    {
        new_word.push_back(v1f.front());
        v1f.pop_front();
    }

    for(int i=0;i<word.size();i++)
    {
        v1.clear();
        v1sv.clear();
        pair<int, int> p;
        for (int x = 0; x < 8; x++)
        {
            v1.push_back(word.front());
            word.pop_front();
        }
        p = SRC(v1);
        sv = S_Box(p.first, p.second);
        v1sv=hex_to_binary(sv);
        for(int x=0;x<8;x++)
        {
            new_word.push_back(v1sv.front());
            v1sv.pop_front();
        }
    }
    return new_word;
}
deque < deque<int> > Key_Generation(deque<int> key_binary)
{
    deque < deque<int> > words(44);
    for (int i = 0; i < 4; i++)
    {
        deque<int> word;
        for (int j = 0; j < 4; j++)
        {
            for (int x = 0; x < 8; x++)
            {
                word.push_back(key_binary.front());
                key_binary.pop_front();
            }
        }
        words[i]=word;
    }

    for(int i=1;i<=10;i++)
    {
        words[4*i]=XOR_deque(words[4*(i-1)],g(words[4*i-1],i));
        for (int j = 1; j<=3; ++j)
        {
            words[4*i+j] =XOR_deque( words[4*i+ j-1],words[4*(i-1)+ j]);
        }
    }

    return words;
}
//--------------------------------------------------------------------------------------------------------------------------
deque<int> Divide_Binary_Domain(deque<int>numerator, deque<int>denomenator, deque<int> remainder)
{
    bool breakk = false;
    for (int i = numerator.size() - 1; i >= 0; i--)
    {
        if (numerator[i] == 1)
        {
            for (int j = denomenator.size() - 1; j >= 0; j--)
            {
                if (denomenator[j] == 1)
                {
                    remainder[i - j] = 1;
                    breakk = true;
                    break;
                }
            }
        }
        if (breakk == true)
        {
            break;
        }
    }
    return remainder;
}
//--------------------------------------------------------------------------------------------------------------------------
deque<int> Multiply_deque_without_mod(deque<int>dq1, deque<int>dq2)
{
    int dq1Size = dq1.size();
    int dq2Size = dq2.size();
    int resultSize = max(dq1Size, dq2Size);

    deque<int> result(resultSize);

    for (int i = dq1Size - 1; i >= 0; i--)
    {
        if (dq1[i] == 1)
        {
            for (int j = dq2Size - 1; j >= 0; j--)
            {
                if (dq2[j] == 1)
                {
                    if (i + j < result.size())
                    {
                        result[i + j] = 1;
                    }
                    else
                    {
                        deque<int> temp = result;
                        ////////Copying the Old Matrix into the Larger one in Correct Places////////
                        result.resize((i + j) + 1);
                        for (int k = temp.size() - 1; k >= 0; k--)
                        {
                            if (temp[k] == 1)
                            {
                                result[k] = 1;
                            }
                            else
                            {
                                result[k] = 0;
                            }
                        }
                        result[i + j] = 1;
                        temp.clear();
                    }
                }
            }
        }
    }
    return result;
}
//--------------------------------------------------------------------------------------------------------------------------
deque<int> ModReduction(deque<int> result)
{
    deque<int> afterMOD;

    deque<int>p_of_x = { 1,1,0,1,1,0,0,0,1 };//X^8+X^4+X^3+X+1
    deque<int>remainder(p_of_x.size() - 1);

    deque<int> div_result;
    deque<int>mult_result;
    deque<int>xor_result = result;
    int size=result.size();
    int max_index_xor = INT_MAX;

    while (max_index_xor >= p_of_x.size() - 1)
    {
        div_result = Divide_Binary_Domain(xor_result, p_of_x, remainder);
        remainder = div_result;
        mult_result = Multiply_deque_without_mod(div_result, p_of_x);
        mult_result.resize(size,0);
        xor_result.resize(size,0);
        xor_result = XOR_deque(xor_result, mult_result);
        afterMOD = xor_result;
        for (int i = xor_result.size() - 1; i >= 0; i--)
        {
            if (xor_result[i] == 1)
            {
                max_index_xor = i;
                break;
            }
        }
        remainder.clear();
        remainder.resize(p_of_x.size() - 1,0);
        size--;
    }
    return afterMOD;
}
//--------------------------------------------------------------------------------------------------------------------------
deque<int> Multiply_deque(deque<int>dq1, deque<int>dq2)///Multiplies Two Deques(Polynomials) while applying Modular Reduction
{
    //takes input reversed
    reverse(dq1.begin(), dq1.end());
    reverse(dq2.begin(), dq2.end());
    bool modReduction = false;

    int dq1Size = dq1.size();
    int dq2Size = dq2.size();
    int resultSize = max(dq1Size, dq2Size);

    deque<int> result(resultSize);

    for (int i = dq1Size - 1; i >= 0; i--)
    {
        if (dq1[i] == 1)
        {
            for (int j = dq2Size - 1; j >= 0; j--)
            {
                if (dq2[j] == 1)
                {
                    if (i + j < result.size())
                    {
                        if (result[i + j] == 1)//Performing XOR while Multiplying --> EX: X^3 + X^3 = (2X^3 -> 0 in binary)
                        {
                            result[i + j] = 0;
                        }
                        else
                        {
                            result[i + j] = 1;
                        }
                    }
                    else
                    {
                        modReduction = true;
                        deque<int> temp = result;
                        ////////Copying the Old Matrix into the Larger one in Correct Places////////
                        result.resize((i + j) + 1);
                        for (int k = temp.size() - 1; k >= 0; k--)
                        {
                            if (temp[k] == 1)
                            {
                                result[k] = 1;
                            }
                            else
                            {
                                result[k] = 0;
                            }
                        }
                        result[i + j] = 1;
                        temp.clear();
                    }
                }
            }
        }
    }
    if (modReduction)//Performing Modular Reduction
    {
        result = ModReduction(result);
        result.resize(8);
        reverse(result.begin(), result.end());
    }
    else
    {
        reverse(result.begin(), result.end());
    }

    return result;
}
//--------------------------------------------------------------------------------------------------------------------------
deque< deque<int> > Multiply_Column(deque< deque<int> > column,int col)
{

    deque< deque<int> > Multiply_Column_output;
    deque < deque < deque<int> > >Fixed_matrix
            {
                    {{0,0,0,0,0,0,1,0},{0,0,0,0,0,0,1,1},{0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,1}},
                    {{0,0,0,0,0,0,0,1},{0,0,0,0,0,0,1,0},{0,0,0,0,0,0,1,1},{0,0,0,0,0,0,0,1}},
                    {{0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,1},{0,0,0,0,0,0,1,0},{0,0,0,0,0,0,1,1}},
                    {{0,0,0,0,0,0,1,1},{0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,1},{0,0,0,0,0,0,1,0}}
            };

    deque<int> Multiply_output;
    deque<int> sum={0,0,0,0,0,0,0,0} ;
    for(int i = 0 ; i < 4 ; i++)
    {
        for(int j = 0 ; j < 4 ; j++)
        {
            Multiply_output = Multiply_deque(Fixed_matrix[i][j], column[j]);
            sum = XOR_deque(Multiply_output, sum);//addition step in Multiplying Column and row/////////////////////////////////
        }
        Multiply_Column_output.push_back(sum);
        sum={0,0,0,0,0,0,0,0};
    }

    return Multiply_Column_output;
}
//--------------------------------------------------------------------------------------------------------------------------
deque< deque< deque<int> > > MixColumn(deque< deque< deque<int> > > deque_2D)//MixColumn Sublayer
{
    deque< deque< deque<int> > > output_deque;
    output_deque.resize(4, deque< deque<int> >(4));
    deque < deque<int> > deque_col;
    deque < deque<int> > Multiply_output;
    for(int col=0;col<4;col++)
    {
        for (int i = 0; i < 4; i++)
        {
            deque_col.push_back(deque_2D[i][col]);
        }

        Multiply_output=Multiply_Column(deque_col,col);
        for (int i = 0; i < 4; i++)
        {
            output_deque[i][col] = Multiply_output[i];
        }
        deque_col.clear();
    }
    return output_deque;
}
//--------------------------------------------------------------------------------------------------------------------------AES
deque < deque<int> > Rounds_keys;
deque<int> AES(deque<int> plainText, deque < deque<int> > words)///AES BLOCK
{
    deque<int> encryptedText;
    deque<int>  key;
    deque<int>  word1;
    deque<int>  plainText1;
    //--------------XOR between PlainText & Key--------------
    int counter1=0;
    for (int i = 0; i < 4; i++)//4 times
    {
        for (int j = 0; j < 4; j++)// rows
        {
            for (int k = counter1; k < counter1+8; k++)// bits
            {
                word1.push_back(words[j][k]);
            }
        }
        counter1+=8;
    }
    cout<<endl<<"plainText before-------------------"<<endl;
    cout<< binToHexa(plainText)<<endl;
    for (int i = 0; i < 32; i+=8)//every 8's
    {
        for (int j = i; j < 128; j+=32)// every 32bit to take first colunm
        {
            for (int k = 0; k < 8; k++)// bits
            {
                plainText1.push_back(plainText[k+j]);
            }

        }
    }
    cout<<endl<<"Round Key------------------ "<<endl;
    cout<< binToHexa(word1)<<endl;
    cout<<endl<<"plainText-------------------"<<endl;
    cout<< binToHexa(plainText1)<<endl;
    plainText = XOR_deque(plainText1, word1);
    Rounds_keys.push_back(word1);
    //--------------Byte Substitution layer--------------
    deque< deque< deque<int> > >Matrix4x4;
    Matrix4x4.resize(4, deque< deque<int> >(4));
    for (int r = 1; r <=10 ; ++r)
    {
        cout<<"----------------------------------------------------------------------- Round "<<r<<" -----------------------------------------------------------------------"<<endl;
        int counter = 0;
        ////////Filling the 4x4 Matrix////////
        for (int i = 0; i < Matrix4x4.size(); i++)
        {
            for (int j = 0; j < Matrix4x4.size(); j++)
            {
                for (int k = 0; k < 8; k++)
                {
                    Matrix4x4[i][j].push_back(plainText[counter]);
                    counter++;
                }
            }
        }
        cout << "Matrix After XORing PlainText and Key then filling the Matrix:" << endl;
        printmatrix(Matrix4x4);
        ////////////////S-Boxes////////////////
        deque< deque< deque<int> > >Matrix4x4_B;//Matrix After S-Boxes
        Matrix4x4_B.resize(4, deque< deque<int> >(4));
        for (int i = 0; i < Matrix4x4.size(); i++)
        {
            for (int j = 0; j < Matrix4x4.size(); j++)
            {
                ////////Each Byte Enters the S-Box////////
                pair<int, int> p;
                p = SRC(Matrix4x4[i][j]);//SRC -> S_box Row Column
                Matrix4x4_B[i][j] = hex_to_binary(S_Box(p.first, p.second));//Filling the new matrix with the binrary form of the S-box Result
            }
        }
        cout << "Matrix After S-Boxes:" << endl;
        printmatrix(Matrix4x4_B);
        //--------------------ShiftRows Sublayer--------------------
        Matrix4x4_B = ShiftRows(Matrix4x4_B);///Shifting Sublayer
        cout << "Matrix After ShiftRows Sublayer:" << endl;
        printmatrix(Matrix4x4_B);
        //--------------------MixColumn Sublayer--------------------
        deque< deque< deque<int> > >Matrix4x4_C;//Matrix After ShiftRows
        Matrix4x4_C.resize(4, deque< deque<int> >(4));
        if(r!=10)
        {
            Matrix4x4_C = MixColumn(Matrix4x4_B);///MixColumn Sublayer
            cout << "Matrix After MixColumn Sublayer:" << endl;
            printmatrix(Matrix4x4_C);
        }
        else
        {
            Matrix4x4_C=Matrix4x4_B;
        }
        //--------------XOR between PlainText & Key--------------
        word1.clear();
        plainText.clear();

        int counter1=0;
        for (int i = 0; i < 4; i++)//4 times
        {
            for (int j = r*4; j <(r*4)+4; j++)// rows
            {
                for (int k = counter1; k < counter1+8; k++)// bits
                {
                    word1.push_back(words[j][k]);
                }
            }
            counter1+=8;
        }
        cout<<endl<<"Round Key------------------ "<<endl;
        cout<< binToHexa(word1)<<endl;


        for (int i = 0; i < Matrix4x4.size(); i++)
        {
            for (int j = 0; j < Matrix4x4.size(); j++)
            {
                for (int k = 0; k < 8; k++)
                {
                    plainText.push_back(Matrix4x4_C[i][j][k]);
                }
            }
        }

        cout<<endl<<"plainText------------------ "<<endl;
        cout<< binToHexa(plainText)<<endl;

        Matrix4x4.clear();
        Matrix4x4.resize(4, deque< deque<int> >(4));

        plainText = XOR_deque(plainText , word1);
        Rounds_keys.push_back(word1);
        cout<<"----------------------------------------------------------------------- END Round "<<r<<" ---------------------------------------------------------------------"<<endl;
    }

    for (int i = 0; i < 32; i+=8)//every 8's
    {
        for (int j = i; j < 128; j+=32)// every 32bit to take first colunm
        {
            for (int k = 0; k < 8; k++)// bits
            {
                encryptedText.push_back(plainText[k+j]);
            }

        }
    }
    return encryptedText;
}
//--------------------------------------------------------------------------------------------------------------------------INVERSE
deque< deque<int> > INVMultiply_Column(deque< deque<int> > column)///Used In INVmixColumn
{

    deque< deque<int> > Multiply_Column_output;
    deque < deque < deque<int> > >Fixed_matrix
            {
                    {{0,0,0,0,1,1,1,0},{0,0,0,0,1,0,1,1},{0,0,0,0,1,1,0,1},{0,0,0,0,1,0,0,1}},
                    {{0,0,0,0,1,0,0,1},{0,0,0,0,1,1,1,0},{0,0,0,0,1,0,1,1},{0,0,0,0,1,1,0,1}},
                    {{0,0,0,0,1,1,0,1},{0,0,0,0,1,0,0,1},{0,0,0,0,1,1,1,0},{0,0,0,0,1,0,1,1}},
                    {{0,0,0,0,1,0,1,1},{0,0,0,0,1,1,0,1},{0,0,0,0,1,0,0,1},{0,0,0,0,1,1,1,0}}
            };

    deque<int> Multiply_output;
    deque<int> sum = { 0,0,0,0,0,0,0,0 };
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            Multiply_output = Multiply_deque(Fixed_matrix[i][j], column[j]);
            sum = XOR_deque(Multiply_output, sum);//addition step in Multiplying Column and row
        }
        Multiply_Column_output.push_back(sum);
        sum = { 0,0,0,0,0,0,0,0 };
    }

    return Multiply_Column_output;
}
//--------------------------------------------------------------------------------------------------------------------------
deque < deque<int> > shift_Right(deque < deque<int> > d, int shift_no)//Shift Right in row ---> INVERSE ShiftRows Sublayer SubFunction
{
    deque<int> temp;
    for (int i = 0; i < shift_no; i++)
    {
        temp = d.back();
        d.pop_back();
        d.push_front(temp);
    }
    return d;
}
//--------------------------------------------------------------------------------------------------------------------------
deque< deque< deque<int> > >INVShiftRows(deque < deque< deque<int> > >deque_2D)// INVERSE ShiftRows Sublayer Function
{
    for (int i = 0; i < deque_2D.size(); i++)
    {
        deque_2D[i] = shift_Right(deque_2D[i], i);
    }
    deque< deque< deque<int> > >dequeOUT = deque_2D;
    return deque_2D;
}
//--------------------------------------------------------------------------------------------------------------------------
deque< deque< deque<int> > > INVMixColumn(deque< deque< deque<int> > > deque_2D , int r)//INVERSE MixColumn Sublayer
{
    deque< deque< deque<int> > > output_deque;
    output_deque.resize(4, deque< deque<int> >(4));

//    for (int i = 0; i < 4; i++)
//    {
//        for (int j = 0; j < 4 ; j++)
//        {
//            for (int k = 0; k < 8; k++)
//            {
//                output_deque[i][j].push_back(MIXcols[r-1].front());
//                MIXcols[r-1].pop_front();
//
//            }
//        }
//    }
//    return output_deque;

    deque < deque<int> > deque_col;
    deque < deque<int> > Multiply_output;
    for (int col = 0; col < 4; col++)
    {
        for (int i = 0; i < 4; i++)
        {
            deque_col.push_back(deque_2D[i][col]);
        }

        Multiply_output = INVMultiply_Column(deque_col);
        for (int i = 0; i < 4; i++)
        {
            output_deque[i][col] = Multiply_output[i];
        }
        deque_col.clear();
    }
    return output_deque;
}
//--------------------------------------------------------------------------------------------------------------------------
string INV_S_Box(int row, int column)
{
    string S_table[16][16] =
            { "52", "09", "6A", "D5", "30", "36", "A5", "38", "BF", "40", "A3", "9E", "81", "F3", "D7", "FB"
                    ,"7C", "E3", "39", "82", "9B", "2F", "FF", "87", "34", "8E", "43", "44", "C4", "DE", "E9", "CB"
                    ,"54", "7B", "94", "32", "A6", "C2", "23", "3D", "EE", "4C", "95", "0B", "42", "FA", "C3", "4E"
                    ,"08", "2E", "A1", "66", "28", "D9", "24", "B2", "76", "5B", "A2", "49", "6D", "8B", "D1", "25"
                    ,"72", "F8", "F6", "64", "86", "68", "98", "16", "D4", "A4", "5C", "CC", "5D", "65", "B6", "92"
                    ,"6C", "70", "48", "50", "FD", "ED", "B9", "DA", "5E", "15", "46", "57", "A7", "8D", "9D", "84"
                    ,"90", "D8", "AB", "00", "8C", "BC", "D3", "0A", "F7", "E4", "58", "05", "B8", "B3", "45", "06"
                    ,"D0", "2C", "1E", "8F", "CA", "3F", "0F", "02", "C1", "AF", "BD", "03", "01", "13", "8A", "6B"
                    ,"3A", "91", "11", "41", "4F", "67", "DC", "EA", "97", "F2", "CF", "CE", "F0", "B4", "E6", "73"
                    ,"96", "AC", "74", "22", "E7", "AD", "35", "85", "E2", "F9", "37", "E8", "1C", "75", "DF", "6E"
                    ,"47", "F1", "1A", "71", "1D", "29", "C5", "89", "6F", "B7", "62", "0E", "AA", "18", "BE", "1B"
                    ,"FC", "56", "3E", "4B", "C6", "D2", "79", "20", "9A", "DB", "C0", "FE", "78", "CD", "5A", "F4"
                    ,"1F", "DD", "A8", "33", "88", "07", "C7", "31", "B1", "12", "10", "59", "27", "80", "EC", "5F"
                    ,"60", "51", "7F", "A9", "19", "B5", "4A", "0D", "2D", "E5", "7A", "9F", "93", "C9", "9C", "EF"
                    ,"A0", "E0", "3B", "4D", "AE", "2A", "F5", "B0", "C8", "EB", "BB", "3C", "83", "53", "99", "61"
                    ,"17", "2B", "04", "7E", "BA", "77", "D6", "26", "E1", "69", "14", "63", "55", "21", "0C", "7D" };
    string outputByte = S_table[row][column];
    return outputByte;
}
deque<int> AES_Decryption(deque<int> encryptedText, deque < deque<int> > words)///AES DECRYPTION BLOCK
{
    deque<int> decryptedText;
    deque<int>  key;
    deque<int>  word1;
    deque<int>  plainText1;
    for (int i = 0; i < 32; i+=8)//every 8's
    {
        for (int j = i; j < 128; j+=32)// every 32bit to take first colunm
        {
            for (int k = 0; k < 8; k++)// bits
            {
                plainText1.push_back(encryptedText[k+j]);
            }

        }
    }
    encryptedText=plainText1;
    deque< deque< deque<int> > >Matrix4x4;
    Matrix4x4.resize(4, deque< deque<int> >(4));
    for (int r = 1; r <= 10; r++)///Iterations
    {
        word1=Rounds_keys.back();
        Rounds_keys.pop_back();
        cout<<endl<<"Round Key------------------ "<<endl;
        cout<< binToHexa(word1)<<endl;
        //--------------XOR between PlainText & Key--------------


        cout<<endl<<"encryptedText before------------------ "<<endl;
        cout<< binToHexa(encryptedText)<<endl;
        encryptedText = XOR_deque(encryptedText, word1);
        cout<<endl<<"encryptedText after------------------ "<<endl;
        cout<< binToHexa(word1)<<endl;
        int counter = 0;
        ////////Filling the 4x4 Matrix////////
        for (int i = 0; i < Matrix4x4.size(); i++)
        {
            for (int j = 0; j < Matrix4x4.size(); j++)
            {
                for (int k = 0; k < 8; k++)
                {
                    Matrix4x4[i][j].push_back(encryptedText[counter]);
                    counter++;
                }
            }
        }
        cout << "Matrix After XORing PlainText and Key :" << endl;
        printmatrix(Matrix4x4);
        //--------------------MixColumn Sublayer--------------------
        deque< deque< deque<int> > >Matrix4x4_C;//Matrix After ShiftRows
        Matrix4x4_C.resize(4, deque< deque<int> >(4));
        if(r!=1)
        {
            Matrix4x4_C = INVMixColumn(Matrix4x4,r-1);///MixColumn Sublayer
            cout << "Matrix After Inverse MixColumn Sublayer:" << endl;
            printmatrix(Matrix4x4_C);
        }
        else
        {
            Matrix4x4_C = Matrix4x4;
        }
        //--------------------ShiftRows Sublayer--------------------
        deque< deque< deque<int> > >Matrix4x4_B;
        Matrix4x4_B.resize(4, deque< deque<int> >(4));
        Matrix4x4_B = INVShiftRows(Matrix4x4_C);///INVERSE Shifting Sublayer
        cout << "Matrix After Inverse ShiftRows Sublayer:" << endl;
        printmatrix(Matrix4x4_B);
        //--------------INVERSE Byte Substitution layer--------------
        ////////////////S-Boxes////////////////
        for (int i = 0; i < Matrix4x4_B.size(); i++)
        {
            for (int j = 0; j < Matrix4x4_B.size(); j++)
            {
                ////////Each Byte Enters the Inverse S-Box////////
                pair<int, int> p;
                p = SRC(Matrix4x4_B[i][j]);//SRC -> S_box Row Column
                //Filling the new matrix with the binrary form of the INVERSE S-box Result
                Matrix4x4_B[i][j] = hex_to_binary(INV_S_Box(p.first, p.second));
            }
        }
        cout << "Matrix After INVERSE S-Boxes:" << endl;
        printmatrix(Matrix4x4_B);

        encryptedText.clear();
        word1.clear();
        for (int i = 0; i < Matrix4x4.size(); i++)
        {
            for (int j = 0; j < Matrix4x4.size(); j++)
            {
                for (int k = 0; k < 8; k++)
                {
                    encryptedText.push_back(Matrix4x4_B[i][j][k]);
                }
            }
        }

        Matrix4x4.clear();
        Matrix4x4.resize(4, deque< deque<int> >(4));

    }


    int counter1=0;
    for (int i = 0; i < 4; i++)//4 times
    {
        for (int j = 0; j < 4; j++)// rows
        {
            for (int k = counter1; k < counter1+8; k++)// bits
            {
                word1.push_back(words[j][k]);
            }
        }
        counter1+=8;
    }
    encryptedText= XOR_deque(encryptedText, word1);

    for (int i = 0; i < 32; i+=8)//every 8's
    {
        for (int j = i; j < 128; j+=32)// every 32bit to take first colunm
        {
            for (int k = 0; k < 8; k++)// bits
            {
                decryptedText.push_back(encryptedText[k+j]);
            }

        }
    }

    return decryptedText;
}
int main()
{
///Entering and handling the input
    string Plain_text, key;
    string Encrypted_text = "";
    string cipher_text;
    cout << "Enter the Plain Text Please:";
    getline(cin, Plain_text);
    while (Plain_text.length() % 16 != 0)
    {
        Plain_text += '*';
    }
    //======================handling the kay
    deque<string> key_hex;
    cout << "Enter the Key Please:";
    getline(cin, key);
    cout << endl;
    for(int i=0;i<key.length();i+=3)
    {
        string hex="";
        hex+=key[i];
        hex+=key[i+1];
        key_hex.push_back(hex);
    }
    while (key_hex.size() != 16)
    {
        key_hex.clear();
        cout << "Please enter another Key :";
        getline(cin, key);
        cout << endl;
        for(int i=0;i<key.length();i+=3)
        {
            string hex="";
            hex+=key[i];
            hex+=key[i+1];
            key_hex.push_back(hex);
        }
        if(key_hex.size() ==16)
        {
            break;
        }
    }

    //======================
    ///Testing
    cout<<"----------------------------Plain_text & Key hex after handling----------------------------"<<endl;
    cout << "Plain_text:" << Plain_text << " size:" << Plain_text.length() << endl;
    cout << "Key hex: "<< endl;
    for (auto it = key_hex.begin(); it != key_hex.end(); it++)
    {
        cout << *it<<" ";
    }
    cout << endl;
    cout<<"-------------------------------------------------------------------------------------------"<<endl;
    //======================
    ///Converting Key hex to binary
    deque<int> key_binary;
    for (auto it = key_hex.begin(); it != key_hex.end(); it++)
    {
        deque<int> hex_bin;
        hex_bin= hex_to_binary(*it);
        for (auto it1 = hex_bin.begin(); it1 != hex_bin.end(); it1++)
        {
            key_binary.push_back(*it1);
        }
        hex_bin.clear();
    }
    cout<<"-----------------------------------------Key binary ----------------------------------------"<<endl;
    cout << "Key binary: "<< endl;
    for (auto it = key_binary.begin(); it != key_binary.end(); it++)
    {
        cout << *it<<" ";
    }
    cout << endl;
    cout <<"size:" << key_binary.size() << endl;
    cout<<"-------------------------------------------------------------------------------------------"<<endl;

    deque < deque<int> > Key_Generation_output;
    Key_Generation_output=Key_Generation(key_binary);
    cout<<"-----------------------------------------Key_Generation_binary-----------------------------"<<endl;
    cout << "Key_Generation_binary: "<< endl;
    deque<int>::iterator ptr1;
    for (auto ptr = Key_Generation_output.begin(); ptr != Key_Generation_output.end(); ptr++)//printing deque
    {
        for (auto ptr1=ptr->begin(); ptr1 != ptr->end(); ptr1++)//printing deque
        {
            cout << *ptr1;
        }
        cout << endl;
    }
    cout << endl;
    cout <<"Key_Generation_output size:" << Key_Generation_output.size() << endl;
    cout<<"-------------------------------------------------------------------------------------------"<<endl;
    cout<<"-----------------------------------------Key_Generation_hex--------------------------------"<<endl;
    cout << "Key_Generation_hex: "<< endl;
    for (int i = 0; i < 44; ++i)
    {
        cout<< binToHexa(Key_Generation_output[i])<<endl;
    }
    cout<<"-------------------------------------------------------------------------------------------"<<endl;
    //======================
    int count = 0;
    int block_no = 1;
    string plain8 = "";
    string FD = "";
    deque<int> cipher_binary(128);
    while (count != Plain_text.length() + 1)
    {
        if ((plain8.length()) % 16 == 0 && count != 0)
        {
            deque<int> plain_binary(128);
            plain_binary = text_toBinary(plain8);
            /////////////////////////////////////////special for other 16s
            plain8 = "";
            plain8 += Plain_text[count];
            /////////////////////////////////////////
            cout << "plain_binary for block " << block_no << ":";
            for (auto it = plain_binary.begin(); it != plain_binary.end(); it++)
            {
                cout << *it;
            }
            cout << endl;
            cout << "plain_binary size for block " << block_no << ":" << plain_binary.size();
            cout << endl;
            cout << "plain_hex for block " << block_no << ":";
            cout << binToHexa(plain_binary)<<endl;
            cout << "decrypt of plain_binary for block " << block_no << ":" << endl;
            Encrypted_text += BinarytoASCII(plain_binary);
            cout << Encrypted_text << endl;
            //======================
            ///AES Encryption Start
            cout<<"//////////////////////////////////////////////CIPHER TEXT//////////////////////////////////////////////"<<endl;
            cout << "Begin of AES for block " << block_no << endl;
            cipher_binary = AES(plain_binary, Key_Generation_output);
            for (auto it = cipher_binary.begin(); it != cipher_binary.end(); it++)
            {
                cout << *it;
            }
            cout << endl;
            cout<<"################################################ CIPHER TEXT ################################################"<<endl;
            cout << "cipher_binary after AES size for block " << block_no << ":" << cipher_binary.size();
            cout << endl;
            Encrypted_text = "";
            cout << "Cipher(Hexa):- " << binToHexa(cipher_binary) <<endl;
            cout<<"################################################ CIPHER TEXT ################################################"<<endl;
            Encrypted_text += BinarytoASCII(cipher_binary);
            cout << Encrypted_text << endl;
            ///AES Encryption End
            cout<<"///////////////////////////////////////////////////////////////////////////////////////////////////////"<<endl;
            //======================
            cout << endl;
            cout<<"//////////////////////////////////////////////DECRYPTED TEXT///////////////////////////////////////////"<<endl;
            cout << "=========Decryption for block " << block_no << "=========" << endl;
            deque<int>Decrypted_text;
            string decrypted_string = "";
            Decrypted_text = AES_Decryption(cipher_binary, Key_Generation_output);
            cout<<"HEX for Decrypted_text"<<binToHexa(Decrypted_text)<<endl;
            //======================
            cout << "Decrypted text Binary for block " << block_no << ":";///Printing Decrypted Binary text
            //Decrypted_text=plain_binary;
            for (auto it = Decrypted_text.begin(); it != Decrypted_text.end(); it++)
            {
                cout << *it;
            }
            //======================
            decrypted_string += BinarytoASCII(Decrypted_text);///Printing Decrypted String text
            cout << endl << "Decrypted String text for block " << block_no << ":" << decrypted_string << endl;
            cout<<"///////////////////////////////////////////////////////////////////////////////////////////////////////"<<endl;
            FD += decrypted_string;
            block_no++;
        }
        else
        {
            plain8 += Plain_text[count];
        }
        count++;
    }
    cout << "Full decrypted string :" << FD << endl;
    //======================

}
