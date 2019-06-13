package cn.edu.bnuz.singleton;

import java.io.IOException;
import java.io.InputStream;
import java.util.HashMap;
import java.util.Map;
import java.util.Properties;

public class ObjectPool {
	private static Map<String,Object> objects = new HashMap<>();
	private static LogInvocationHandler loghandler = new LogInvocationHandler();
	
	
//参数类名是全路径，cn.edu.bnuz.singleton.ICar
	public Object getObject(String classname)  {
		Object objectProxy = null;
		Class clazz;
		//o = objects.get(classname);
		if(objects.get(classname)==null){
			try {//改到配置文件中--使用键值对--Properties
				//需要使用properties类去读取文件配置
				
		            Properties prop = new Properties();		        
		            InputStream in 
		              = ObjectPool.class.getClassLoader()
		                .getResourceAsStream("hzj.properties");
		            prop.load(in);
		            //直接输出prop对象
		            System.out.println("直接输出prop对象:"+prop);
		            //获取name的值
		            String name=prop.getProperty(classname);
		            System.out.println("name:"+name);
		            clazz = Class.forName(name);
					o = clazz.newInstance();
					Class proxyinterface = Class.forName(classname);
					Object objectProxy = Proxy.newProxyInstance(
						this.getClass().getClassLoader(),
						new Class[] {proxyinterface},
						loghandler
					);
					
					//放入对象池
					objects.put(classname, objectProxy);
		         

				/*
				if (classname.equalsIgnoreCase("cn.edu.bnuz.singleton.ICar"))
				{
				  clazz = Class.forName("cn.edu.bnuz.singleton.BMWCar");
				  o = clazz.newInstance();
				}else if(classname.equalsIgnoreCase("cn.edu.bnuz.singleton.IStudent"))
				{
				  clazz = Class.forName("cn.edu.bnuz.singleton.MiddleStudent");
			      o = clazz.newInstance();
				}*/
					
				
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} 
			
			
		}

		return o;
	}

}
