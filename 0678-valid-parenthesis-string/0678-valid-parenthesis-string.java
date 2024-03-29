class Solution {
    public boolean checkValidString(String s) {
        // initially assume * -> open and take into account. if in the last, close count is less then *count then return true. mx close count = *count+1
        int n = s.length();
        Stack<Character> stack = new Stack<>();

        int starC = 0, closeC = 0, openC = 0;
        for(int i=0; i<n; i++){
            Character ch = s.charAt(i);
            if(ch == '*'){
                starC++;
                if(stack.isEmpty() == false && stack.peek() == '(') stack.pop();
            }
            else if(ch == ')'){
                closeC++; 
                if(stack.isEmpty() == false && stack.peek() == '(') {
                    stack.pop();
                    }
                if(openC + starC < closeC) return false;

            }
            else{ // open
                openC++;
                stack.push('(');
            }
        }
        if(stack.isEmpty() == false && stack.peek() == '(') return false;
        if(closeC > openC+starC+1) return false;
        return true;
    }
}