/* FIRST EXAMPLE WORK WELL
import org.apache.commons.lang3.*;
public class syslogFromJava{
        public static void main(String[] args){
                String x = "abcd";
                System.out.println(x);
                //System.out.println(StringUtils.capitalize(x));
        } 
}
*/

import org.apache.log4j.*;
import org.apache.log4j.Logger;
import org.apache.log4j.LogManager;

public class syslogFromJava{

	Logger logger = Logger.getLogger(syslogFromJava.class);
	
	public static void main(String[] args) {
	
		syslogFromJava obj = new syslogFromJava();
		obj.runMe("mkyong");
		
	}
	
	private void runMe(String parameter){
		
		if(logger.isDebugEnabled()){
			logger.debug("This is debug : " + parameter);
		}
		
		if(logger.isInfoEnabled()){
			logger.info("This is info : " + parameter);
		}
		
		logger.warn("This is warn : " + parameter);
		logger.error("This is error : " + parameter);
		logger.fatal("This is fatal : " + parameter);
	}
	
}