import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;


public class Attori{
    public static void main(String[] args) {
        Map<String,Set<String>> map =new HashMap<String,Set<String>>();
        Map<String,ArrayList<String>> professioni= new HashMap<String,ArrayList<String>>(); 

        try {
            BufferedReader in = new BufferedReader(new FileReader(args[0]));
            String line;
            while((line = in.readLine())!=null){
                
                String[] splitted = line.split("\t");
                String[] role = splitted[4].split(",");
                HashSet<String> s = new HashSet<String>();
                for (String str:role){
                    s.add(str);
                }
                map.put(splitted[1], s);
            }
            for(String key :map.keySet()){
                for(String setString:map.get(key)){
                    if(professioni.get(setString)==null){
                        professioni.put(setString,new ArrayList<String>());
                        professioni.get(setString).add(key);
                    }else{
                        professioni.get(setString).add(key);
                    }
                }
            }
            in.close();
        } catch (Exception e) {
            e.printStackTrace();
        }

        try {
            BufferedWriter attrici = new BufferedWriter(new FileWriter("attrici.txt"));
            for(String prof :professioni.keySet()){
                BufferedWriter writer = new BufferedWriter(new FileWriter(prof +".txt"));
                professioni.get(prof).sort((arg1, arg2) -> {return arg1.compareTo(arg2);});
                for(String person :professioni.get(prof)){
                    writer.write(person+"\n");
                    if(prof.equalsIgnoreCase("Actress")){
                        attrici.write(person+"\n");
                    } 
                    
                }
                

                writer.close();
            }
            attrici.close();
        } catch (Exception e) {
            // TODO: handle exception
        }
    }
}