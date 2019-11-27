


int main() {


}

//Function to convert char[] to int
int atoi(char s[]) {

    int i, n;

    n = 0;
    //While the char targeted is a digit,
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i) {
        //Multiply existing number by 10 (shift left)
        //and add the numerical value,
        //which is the char digit - '0'
        //
        //'0' - '0' = 0, and all in order, therefore:
        //'1' - '0' = 1
        //'5' - '0' = 5
        //
        //etc. etc.
        n = 10 * n + (s[i] - '0');
    }
    return n;
}

//Converts char passed to lowercase
int lower(int c) {
    if(c >= 'A' && c <= 'Z') {
        return c + 'a' - 'A';
    } else {
        return c;
    }
}
