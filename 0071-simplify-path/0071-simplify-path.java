class Solution {

    public String simplifyPath(String path) {
        int n = path.length();
        StringBuilder directory = new StringBuilder("");
        Stack<String> directories = new Stack<>();
        StringBuilder canonicalPath = new StringBuilder("");
        for (int i = 0; i < n; i++) {
            if (path.charAt(i) == '/') {
                if (directory.length() == 0) continue;
                if (directory.toString().equals(".")); else if (directory.toString().equals("..")) {
                    if (!directories.isEmpty()) directories.pop();
                } else directories.push(directory.toString());
                directory.setLength(0);
            } else directory.append(path.charAt(i));
        }
        if (directory.length() > 0) {
            if (directory.toString().equals(".")); else if (directory.toString().equals("..")) {
                if (!directories.isEmpty()) directories.pop();
            } else directories.push(directory.toString());
        }
        n = directories.size();
        if (n == 0) return "/";
        String[] directoryNames = new String[n];
        for (int i = 0; i < n; i++) {
            directoryNames[i] = (String) directories.pop();
        }
        for (int i = n - 1; i >= 0; i--) {
            canonicalPath.append("/" + directoryNames[i]);
        }
        return canonicalPath.toString();
    }
}
