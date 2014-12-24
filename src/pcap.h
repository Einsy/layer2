#ifndef NODE_PCAP_H
#define NODE_PCAP_H

#include <node.h>
#include <pcap/pcap.h>


class Pcap : public node::ObjectWrap {

public:

    static void init(v8::Handle<v8::Object> exports);

private:

    Pcap();
    ~Pcap();

    static v8::Handle<v8::Value> init(const v8::Arguments& args);
    static v8::Handle<v8::Value> activate(const v8::Arguments& args);
    static v8::Handle<v8::Value> close(const v8::Arguments& args);
    static v8::Handle<v8::Value> dispatch(const v8::Arguments& args);
    static v8::Handle<v8::Value> fromDevice(const v8::Arguments& args);
    static v8::Handle<v8::Value> fromSavefile(const v8::Arguments& args);
    static v8::Handle<v8::Value> getDatalink(const v8::Arguments& args);
    static v8::Handle<v8::Value> inject(const v8::Arguments& args);
    static v8::Handle<v8::Value> setBufferSize(const v8::Arguments& args);
    static v8::Handle<v8::Value> setFilter(const v8::Arguments& args);
    static v8::Handle<v8::Value> setPromisc(const v8::Arguments& args);
    static v8::Handle<v8::Value> setRfMon(const v8::Arguments& args);
    static v8::Handle<v8::Value> setSnapLen(const v8::Arguments& args);
    static v8::Handle<v8::Value> stats(const v8::Arguments& args);
    static v8::Handle<v8::Value> breakLoop(const v8::Arguments& args);
    static void onPacket(u_char *callback_p, const struct pcap_pkthdr* pkthdr, const u_char* packet);

    v8::Persistent<v8::Function> packet_ready_cb;
    struct bpf_program filter;
    pcap_t *handle;
    char *buffer_data;
    size_t buffer_length;
    size_t buffer_offset;

};

#endif
