/** 
 * I found this code online from your previous posted answers for your past cmsi 282 class on http://cs.lmu.edu/~ray/classes/a/assignment/2/answers/
 **/

//package edu.lmu.cs.crypto;

/**
 * An auto-key Vigenere cipher. During encryption, the input text is used for
 * the key stream after the initial key is used up. During decryption, we get
 * the key characters from the plaintext we are recovering.
 */

public class AutoKeyVigenere {

	//Junit no longer exists so this is my test of the AutokEyVigenere class
	/** public static void main(String[] args) {
		String[] messages = { "Attack @T DaWN!", "",
				"fjh94h8\u3032\u412b2r98h923h", "%" };
		String[] keys = { "......11111111111111111111111111111..",
				"\uffff,\uff73" };
		for (String message : messages) {
			for (String key : keys) {
				String cipherText = AutoKeyVigenere.encipher(message, key);
				String recoveredText = AutoKeyVigenere
						.decipher(cipherText, key);
				System.out.println("The original message is: "+message+". The recovered text is: "+ recoveredText);
				System.out.println("They should be equal.");
				System.out.println("The cipher for this message is: "+cipherText);
			}
		}
		
		try { 
			AutoKeyVigenere.encipher("hello", ""); //This should throw an illegal arg exception 
		        }catch (Exception e) {
		  // try and catch to see if illegal argument exception is thrown. If it's thrown we enter the catch. 
		        System.out.println("\n Illegal Argument Exception is thrown.");
		        }  
		    
		

	} */

	/**
	 * Encrypt the given plain text with the given key.
	 */
	public static String encipher(String plaintext, String key) {
		return encipher(plaintext, key, 1);
	}

	/**
	 * Decrypt the given ciphertext with the given key.
	 */
	public static String decipher(String ciphertext, String key) {
		return encipher(ciphertext, key, -1);
	}

	private static String encipher(String text, String key, int multiplier) {
		if ("".equals(key)) {
			throw new IllegalArgumentException("Key cannot be empty");
		}
		StringBuilder builder = new StringBuilder();
		int keyLength = key.length();
		for (int i = 0, n = text.length(); i < n; i++) {
			char k = i < keyLength ? key.charAt(i) : multiplier == 1 ? text
					.charAt(i - keyLength) : builder.charAt(i - keyLength);
			builder.append((char) (k * multiplier + text.charAt(i)));

		}
		return builder.toString();
	}

}