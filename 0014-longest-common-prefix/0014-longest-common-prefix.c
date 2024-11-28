char* longestCommonPrefix(char** strs, int strsSize) {
    char* prefixo = strs[0];
    
    for(int i = 1; i < strsSize; i++){
        while(strncmp(prefixo, strs[i],strlen(prefixo))!= 0){
            prefixo[strlen(prefixo)- 1] = '\0'; 
        }
    }
    
if(strsSize != 0){
    return prefixo;
}else{
    return "";
}
}