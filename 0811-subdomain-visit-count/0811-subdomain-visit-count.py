class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        counts = {}
        for cpdomain in cpdomains:
            repCount, domain = cpdomain.split(' ')
            count = int(repCount)
            fragments = domain.split('.')

            for i in range(len(fragments)):
                subdomain = '.'.join(fragments[i:])
                counts[subdomain] = counts.get(subdomain, 0) + count
        
        ans = []
        for domain, count in counts.items():
            ans.append(f"{count} {domain}")
        
        return ans