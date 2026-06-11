class Solution:
    def validIPAddress(self, queryIP: str) -> str:
        def isValidIPv4(ip : str) -> bool:
            parts = ip.split('.')
            if len(parts) != 4 :
                return False            
            for part in parts:
                if not part.isdigit():
                    return False
                if len(part) > 1 and part[0] == '0':
                    return False
                if not (0 <= int(part) <= 255) :
                    return False
            return True
        
        def isValidIPv6(ip : str) -> bool:
            parts = ip.split(':')
            if len(parts) != 8 :
                return False  
            hexadec = set("0123456789abcdefABCDEF")
            for part in parts:
                if not (1 <= len(part) <= 4) :
                    return False
                for p in part:
                    if not p in hexadec:
                        return False
            return True
        
        if '.' in queryIP and isValidIPv4(queryIP):
            return "IPv4"
        elif ':' in queryIP and isValidIPv6(queryIP):
            return "IPv6"
        else :
            return "Neither"