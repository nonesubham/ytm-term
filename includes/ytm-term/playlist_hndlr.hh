#include <string>
#include <array>
#include <vector>

class playlist_hndlr {
protected:
    std::string playlistURL;
    int index = 0;
    std::vector<std::array<std::string, 3>> queue;

public:
    virtual ~playlist_hndlr() = default;

    int getIndex() { return index; }
    void setIndex(int indx) { index = indx; }

    std::array<std::string, 3> next() {
        if (index < (int)queue.size() - 1)
            index++;
        return queue[index];
    }

    std::array<std::string, 3> previous() {
        if (index > 0)
            index--;
        return queue[index];
    }
    
    virtual void fetchPlaylist(const std::string& url) = 0;
    
};
