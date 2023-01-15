	if(list_root->letter == '\000'){
		list_root->letter = letter_to_add;
		list_root->count = 1;	
		return;	
	}