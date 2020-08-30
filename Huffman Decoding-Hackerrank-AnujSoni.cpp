void decode_huff(node * root, string s) {
    node* ptr = root;
    string ans;
    for(int i=0;i<=s.length();i++){
        if(!ptr->left && !ptr->right){
            ans.push_back(ptr->data);
            ptr = root;
            i--;
        }
        else if(s[i] == '0')
            ptr = ptr->left;
        else if(s[i] == '1')
            ptr = ptr->right;
    }
    cout<<ans<<endl;
}
