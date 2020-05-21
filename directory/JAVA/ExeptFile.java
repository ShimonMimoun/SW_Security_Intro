import java.io.*; 

//I create an Except File class which will allow me to write to a file

public class ExeptFile{


    private final FileWriter current_file;//Current path 
    private final boolean flag=true;//should i complete the file or write it again?
    private static  String TEXTE="Write Here"; // The text to write in the file
       
    public ExeptFile(){// Default constractor which is initialized to null...
            current_file = null;
        }

        public ExeptFile (String path) throws IOException {//Creator who receives a String and who creates a FileWriter object with the path he receives 
            current_file = new FileWriter(path,flag);
            
        }
        //Throws an exception : IOEXCEPTION
        public void write_to_path (String file) throws IOException {// Function that will allow us to write to my file 
            
            //Try : Catch
            
            try {
                // System.out.println(file +"test");
                current_file.write(file + "\n");//Write in the file my element
                current_file.close();//close the file afterwards so as not to create a problem or hacking
                
            } catch (NullPointerException expt) {//if it catches a NullPointerException
            System.out.println("Write with a destination == NULL  ");
            StringWriter sw = new StringWriter(); 
            PrintWriter pw = new PrintWriter(sw); 
            expt.printStackTrace(pw); 
            System.out.println("Error:\n" + sw.toString());
            
        }
        }

        //Test function that returns which function without returning an exception
        public static void test_ExptFile1() {

            try {
                ExeptFile curent = new ExeptFile("file_write.txt");//call to the constractor with parameter 
                curent.write_to_path(TEXTE);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }


        //Test function that returns which function with returning an exception
        public static void test_ExptFile2() {

            try {
                ExeptFile curr = new ExeptFile();//call to the constractor without parameter and a pointer == null 
                curr.write_to_path(TEXTE);//try writing to null -> therefore returns an exception
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        // Main Function
        public static void main(String[] args){
            test_ExptFile1();
            test_ExptFile2();
    }
}
