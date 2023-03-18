class BrowserHistory {
    int pos=-1;
    Stack<String> stack=new Stack<String>();
    public BrowserHistory(String homepage) {
        pos++;
        stack.add(homepage);
    }
    public void visit(String url) {  
       int len=stack.size();
       while((pos+1)<len){
           stack.pop();
           len--;
       }
       stack.add(url);
       pos++;
    }
    public String back(int steps) {
        if(stack.isEmpty()) return null; 
        if(pos+1>steps){
            pos=pos-steps;
            return stack.get(pos);
        }else{
            pos=0;  
            return stack.get(0); 
        }  
    }
    public String forward(int steps) {
        if(stack.isEmpty()) return null;
        if((stack.size()-(pos+1))>steps){
             pos=pos+steps;     
             return stack.get(pos);
        }else{
            pos=stack.size()-1;
            return stack.get(pos);
        }
    }
}