# Performence testing

## GC and Memory usage.

### GC
```Java
/**
trigger GC
System.gc() and Runtime.gc() both are same. 
System.gc() is effectively equivalent to Runtime.gc(). System.gc()internally calls Runtime.gc().
The only difference is System.gc() is a class method where as Runtime.gc() is an instance method. 
So, System.gc() is more convenient.
*/

System.gc()

or 

Runtime.getRuntime().gc()
```

### Memory usage:
```Java

/**
Memory - free memory.
*/
Runtime runtime = Runtime.getRuntime();
double currentMemory = ( (double)((double)(Runtime.getRuntime().totalMemory()/1024)/1024))- ((double)((double)(Runtime.getRuntime().freeMemory()/1024)/1024));

/**
JMX, The MXBeans (ThreadMXBean, etc) provided will give you Memory and CPU usages.
*/
import java.lang.management.ManagementFactory;
import com.sun.management.OperatingSystemMXBean;

OperatingSystemMXBean operatingSystemMXBean = (OperatingSystemMXBean) ManagementFactory.getOperatingSystemMXBean();
operatingSystemMXBean.getSystemCpuLoad();


/**
CPU load
*/
double getCpuLoad() {
    OperatingSystemMXBean osBean =
        (com.sun.management.OperatingSystemMXBean) ManagementFactory.
        getPlatformMXBeans(OperatingSystemMXBean.class);
    return osBean.getProcessCpuLoad();
}



    OperatingSystemMXBean operatingSystemMXBean = (OperatingSystemMXBean) ManagementFactory.getOperatingSystemMXBean();
    RuntimeMXBean runtimeMXBean = ManagementFactory.getRuntimeMXBean();
    int availableProcessors = operatingSystemMXBean.getAvailableProcessors();
    long prevUpTime = runtimeMXBean.getUptime();
    long prevProcessCpuTime = operatingSystemMXBean.getProcessCpuTime();
    double cpuUsage;
    try
    {
        Thread.sleep(500);
    }
    catch (Exception ignored) { }

    operatingSystemMXBean = (OperatingSystemMXBean) ManagementFactory.getOperatingSystemMXBean();
    long upTime = runtimeMXBean.getUptime();
    long processCpuTime = operatingSystemMXBean.getProcessCpuTime();
    long elapsedCpu = processCpuTime - prevProcessCpuTime;
    long elapsedTime = upTime - prevUpTime;

    cpuUsage = Math.min(99F, elapsedCpu / (elapsedTime * 10000F * availableProcessors));
    System.out.println("Java CPU: " + cpuUsage);

```


### -Xmx
First of all remember that the parameter you set with -Xmx (since that's the way I suppose you are setting your heap size) 
is the **size of heap available** to your Java code, **not the amount of memory the JVM will consume**. 
The difference comes from housekeeping structures that the JVM keeps (garbage collector structures, JIT overhead etc.), 
sometimes memory allocated by native code, buffers, and so on. 
The size of this additional memory depends on JVM version, the app you are running, and other factors, 
but I've seen JVMs allocate twice as much RAM as the heap size visible to the application. 
For the average case, I usually consider 50% to be a safe margin, with 20-30% acceptable. 
If you set your heap size to be close to amount of RAM in your machine, you will hit the swap and performance will suffer.

**Perm gen is a separate space from the heap** at least in Oracle's JDK 6. 
It is separate because it undergoes completely different memory management rules than the regular heap. 
- In Hotspot Java 6, PermGen space is independent from the max heap size argument (-Xmx and -Xms control only the Young/OldGen sizes). 
The PermGen space size is given by the -XX:PermSize and -XX:MaxPermSize. 
See Java SE 6 HotSpot[tm] Virtual Machine Garbage Collection Tuning(http://www.oracle.com/technetwork/java/javase/gc-tuning-6-140523.html)
- UPDATE: In Hotspot Java 8, there is no PermGen space anymore and the objects reside in the Young/Old Generation spaces.
