#pragma once
#include <vector>
#include <string>
#include "MetaInfo.hh"


class IService {
public:
    virtual ~IService() = default;
    virtual bool canHandleURL(const std::string& url) const = 0;
    virtual std::string getServiceName() const = 0;
};


class ISingleTrackExtractor : public virtual IService {
public:
    virtual ~ISingleTrackExtractor() = default;
    virtual MetaInfo extractTrackInfo(const std::string& url) = 0;
};

class IPlaylistExtractor : public virtual IService {
public:
    virtual ~IPlaylistExtractor() = default;
    
    virtual std::vector<MetaInfo> extractPlaylistInfo(const std::string& playlistUrl) = 0;
};


class ISearchProvider : public virtual IService {
public:
    virtual ~ISearchProvider() = default;
    
    virtual std::vector<MetaInfo> search(const std::string& query) = 0;
};



class IAudioURLProvider : public virtual IService {
public:
    virtual ~IAudioURLProvider() = default;
    

    virtual std::string getAudioURL(const std::string& serviceUrl) = 0;
};