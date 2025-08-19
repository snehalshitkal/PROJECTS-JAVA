///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//          Project Name :  Packer Unpacker
//          Module       :  Packer_Package
//          Description  :  Only Accept input from user.
//                          Main Login in User defined packagae MArvellous Packer class.
//          Author       :  Snehal Rohit Shitkal
//          Date         :  22/8/2025
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

import java.util.*;
import java.io.*;

import MarvellousPackerUnpacker.MarvellousPacker;

///////////////////////////////////////////////////////////////////////////////////////////////////////////
class Packer_Package
{
    public static void main(String A[])
    {
       try
       {
            Scanner sobj = new Scanner(System.in);

            System.out.println("Enter the name of Directory that you want to pack:");
            String DirName = sobj.nextLine();

            System.out.println("Enter the name of file that you want to packing:");
            String PackName = sobj.nextLine();

            
            MarvellousPacker mobj =new MarvellousPacker(PackName,DirName);
            mobj.PackingActivity();

            
       }
       catch(Exception eobj)
       {

       } 
    }//end of main
}//end of Packer_Pakaages class


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////