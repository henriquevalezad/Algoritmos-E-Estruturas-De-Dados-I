bool isPalindrome(int x) {
    long palindromo = 0;
    int original = x;

    while(x > 0){
    int ultimoDigito = x % 10;
        palindromo = palindromo * 10 + ultimoDigito;
        x /= 10; 
    }
    if(original == palindromo){
        return true;
    }else{
        return false;
    }

}