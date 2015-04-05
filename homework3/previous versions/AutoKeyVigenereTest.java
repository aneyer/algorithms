//package edu.lmu.cs.crypto;

import org.junit.Assert;
import org.junit.Test;

public class AutoKeyVigenereTest{
	@Test
	public void testRoundTrip(){
		String[] messages = {
			"Attack @T DaWN!", "", "fjh94h8\u3032\u412b2r98h923h","%"	
		};
		String[] keys = {
			"......11111111111111111111111111111..","\uffff,\uff73"	
		};
		for (String message: messages){
			for(String key: keys){
				String cipherText = AutoKeyVigenere.encipher(message, key);
				String recoveredText = AutoKeyVigenere.decipher(cipherText, key);
				Assert.assertEquals(message, recoveredText);
			}
		}
	}
	
	@Test(expected=IllegalArgumentException.class)
	public void testEmptyKey(){
		AutoKeyVigenere.encipher("hello", "");
	}
	
}