/*
获取一个String的所有可能子集
*/

  public List<String> findAllSubsetStrings(String s) {
        
        List<String> res = new ArrayList<String>();
        
        for (int i = 0; i < (1 << s.length()); i++) {  //i < s.length的2进制数，共2的s.length次方个数
            String t = "";
            for (int j = 0; j < s.length(); j++) {
                if (((i >> j) & 1) != 0)
                    t += s.charAt(j);
            }
            
            res.add(t);
                
        }
        
        return res;
    }
