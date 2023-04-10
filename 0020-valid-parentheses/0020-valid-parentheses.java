class Solution {

    public boolean isValid(String str) {
        Stack<Character> s = new Stack<>();
        Map<Character, Character> m = new HashMap<>() {

            {
                put('}', '{');
                put(')', '(');
                put(']', '[');
            }
        };
        for (char c : str.toCharArray()) {
            if (c == '(' || c == '{' || c == '[') {
                s.push(c);
                continue;
            }
            if (s.isEmpty() || s.peek() != m.get(c)) return false;
            s.pop();
        }
        return s.isEmpty();
    }
}
