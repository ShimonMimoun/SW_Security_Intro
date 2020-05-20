import java.io.*; 


public class ExeptFile{

    private final FileWriter current_file;
    private final boolean flag=true;
    private static  String TEXTE="Write Here";
        public ExeptFile(){
            current_file = null;
        }

        public ExeptFile (String path) throws IOException {
            current_file = new FileWriter(path,flag);
            
        }

        public void write_to_path (String file) throws IOException {

            try {
System.out.println(file +"test");
                current_file.write(file + "\n");
                current_file.close();
                
            } catch (NullPointerException e) {
                System.out.println("Write with a destination == NULL  ");
            StringWriter sw = new StringWriter(); 
            PrintWriter pw = new PrintWriter(sw); 
                e.printStackTrace(pw); 
                System.out.println("Error:\n" + sw.toString());
            }
        }


        public static void test_ExptFile1() {

            try {
                ExeptFile curent = new ExeptFile("file_write.txt");
                curent.write_to_path(TEXTE);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }



        public static void test_ExptFile2() {

            try {

                ExeptFile curr = new ExeptFile();
                curr.write_to_path(TEXTE);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

    public static void main(String[] args){
            test_ExptFile1();
            test_ExptFile2();
    }
}
