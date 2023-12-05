// NAME : HARSHAL PATIL
// ROLL NO : 44 

class SharedResource 
{
    private int data;
    private boolean available = false;

    public synchronized void produce(int value) throws InterruptedException
	 {
        	while (available) 
		{
            wait();
        	}

        data = value;
        System.out.println("Produced: " + value);
        available = true;

        notify();
    	}

    public synchronized void consume() throws InterruptedException 
	 {
       	 while (!available)
		 {
            	wait();
        	 }

        int consumedValue = data;
        System.out.println("Consumed: " + consumedValue);
        available = false;

        notify();
   	 }
}

class Producer extends Thread 
{
    private SharedResource sharedResource;

    public Producer(SharedResource sharedResource) 
    {
        this.sharedResource = sharedResource;
    }

    @Override
    public void run() 
     {
        try 
        {
            for (int i = 0; i < 5; i++) 
            {
                sharedResource.produce(i);
                Thread.sleep(1000); // Simulating some time for production
            }
        } catch (InterruptedException e) 
          {
            e.printStackTrace();
        }
    }
}

class Consumer extends Thread 
{
    private SharedResource sharedResource;

    public Consumer(SharedResource sharedResource) 
    {
        this.sharedResource = sharedResource;
    }

    @Override
    public void run() 
    {
        try {
            for (int i = 0; i < 5; i++) {
                sharedResource.consume();
                Thread.sleep(1500); // Simulating some time for consumption
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class Fifth 
   {
      public static void main(String[] args)
      {
        SharedResource sharedResource = new SharedResource();
        Producer producer = new Producer(sharedResource);
        Consumer consumer = new Consumer(sharedResource);

        producer.start();
        consumer.start();
     }
}

