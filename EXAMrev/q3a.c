ptr_charNode charList(char* str){
	ptr_charNode head = malloc(node_size);
	if(head == NULL){
		printf("error");
		return NULL;
	}
	head-> data =str[0];
    if(*(str++)!='\0'){
    	head-> next =charList(str);
    }else{
    	head -> next =NULL;
    }
    return head;
}