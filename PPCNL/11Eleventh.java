// NAME : HARSHAL PATIL
// ROLL NO : 44 

import java.net.InetAddress;
import java.net.UnknownHostException;

public class Eleventh {

    public static void main(String[] args) {
        try {
            // Input IP address and subnet mask prefix length
            String ipAddress = "192.168.1.0"; // Example IP address
            int subnetPrefixLength = 24; // Example subnet mask prefix length

            // Calculate subnet mask
            String subnetMask = calculateSubnetMask(subnetPrefixLength);
            System.out.println("Subnet Mask: " + subnetMask);

            // Display IP addresses in the subnet
            displaySubnetIPs(ipAddress, subnetMask);

        } catch (UnknownHostException e) {
            e.printStackTrace();
        }
    }

    private static String calculateSubnetMask(int prefixLength) {
        int subnetMaskValue = 0xFFFFFFFF << (32 - prefixLength);
        byte[] subnetMaskBytes = {
                (byte) ((subnetMaskValue >> 24) & 0xFF),
                (byte) ((subnetMaskValue >> 16) & 0xFF),
                (byte) ((subnetMaskValue >> 8) & 0xFF),
                (byte) (subnetMaskValue & 0xFF)
        };

        try {
            return InetAddress.getByAddress(subnetMaskBytes).getHostAddress();
        } catch (UnknownHostException e) {
            e.printStackTrace();
            return null;
        }
    }

    private static void displaySubnetIPs(String ipAddress, String subnetMask) {
        try {
            InetAddress networkAddress = InetAddress.getByName(ipAddress);
            InetAddress subnetMaskAddress = InetAddress.getByName(subnetMask);

            byte[] networkBytes = networkAddress.getAddress();
            byte[] subnetMaskBytes = subnetMaskAddress.getAddress();

            for (int i = 0; i < 4; i++) {
                networkBytes[i] = (byte) (networkBytes[i] & subnetMaskBytes[i]);
            }

            System.out.println("IP addresses in the subnet:");
            for (int i = 1; i <= 255; i++) {
                networkBytes[3] = (byte) i;
                InetAddress subnetAddress = InetAddress.getByAddress(networkBytes);
                System.out.println(subnetAddress.getHostAddress());
            }

        } catch (UnknownHostException e) {
            e.printStackTrace();
        }
    }
}
