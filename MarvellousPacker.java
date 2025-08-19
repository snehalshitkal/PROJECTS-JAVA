///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//          Project Name :  Packer Unpacker
//          Module       :  MarvellousPacker
//          Description  :  Create user define package. Accept directory name and file name from user.Name of file and its size and 
//                          checksum written in log file which created system directory and display packing report.
//          Author       :  Snehal Rohit Shitkal
//          Date         :  22/8/2025
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

package MarvellousPackerUnpacker;

import java.util.*;
import java.io.*;

public class MarvellousPacker
{
    private String PackName;
    private String DirName;

    public MarvellousPacker(String A,String B)
    {
        this.PackName = A;
        this.DirName = B;
    }
    public void PackingActivity()
    {
        try
       {
            System.out.println("------------------------------------------------------------");
            System.out.println("-----------------Marvellous Packer Unpacker-----------------");
            System.out.println("------------------------------------------------------------");
            System.out.println("------------------------Packing Activity--------------------");
            System.out.println("------------------------------------------------------------");
            
            int i = 0,j = 0;
            int iRet = 0,icountFile = 0;
            
            File fobj = new File(DirName);
            
            //Check the existance of directory
            if((fobj.exists()) &&( fobj.isDirectory()))
            {
                System.out.println(DirName+" is Successfully opened:");

                File packobj = new File(PackName);

                //create a packed file
                boolean bRet = packobj.createNewFile();

                if(bRet == false)
                {
                    System.out.println("Unable to create create pack file:");
                    return;
                }

                System.out.println("Packed file gets Successfully created with name "+PackName);

                //Retrive all files from directory
                File Arr[] = fobj.listFiles();

        
                //Packed file object
                FileOutputStream foobj = new FileOutputStream(packobj);

                //Buffer for read and write activity
                byte Buffer[] = new byte[1024];
               

                String Header = null;

                //Directory traversal
                for(i = 0;i< Arr.length;i++)
                {
                    Header = Arr[i].getName() + " " +Arr[i].length();
                    

                //Loop to form 100 byte header
                for(j = Header.length();j<100;j++)
                {
                    Header = Header + " ";
                }  

                //Write header into packed file
                foobj.write(Header.getBytes());


                //Open file for director reading
                FileInputStream fiobj = new FileInputStream(Arr[i]);

                //Write content of file into packed file
                while ((iRet = fiobj.read(Buffer))!= -1)
                {
                    foobj.write(Buffer,0,iRet);

                    System.out.println("File named scanning:"+Arr[i].getName());
                    System.out.println("File size is read:"+iRet);
                }
                
                fiobj.close();
                icountFile++;

                }
                System.out.println("Packing Activity Done");
                System.out.println("------------------------------------------------------------");
                System.out.println("---------------------Statistical Report ---------------------");
                System.out.println("-------------------------------------------------------------");
                
                //To be add
                System.out.println("Total Files Packed: "+icountFile);
                System.out.println("--- ---------------------------------------------------------");
                System.out.println("-----------------Thank you for using our application---------");
                System.out.println("-------------------------------------------------------------");
            
            
            }

            else
            {
                System.out.println("There is no such Directory:");
            }
       }
       catch(Exception eobj)
       {

       } 
    }
}
 
