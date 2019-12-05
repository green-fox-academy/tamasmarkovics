package com.example.demo.models.DTOs;

import com.example.demo.models.entities.LogEntry;

import java.util.List;

public class LogEntryDTO {
    private List<LogEntry> entry;
    private long count;

    public List<LogEntry> getEntry() {
        return entry;
    }

    public void setEntry(List<LogEntry> entry) {
        this.entry = entry;
    }

    public long getCount() {
        return count;
    }

    public void setCount(long count) {
        this.count = count;
    }

    public LogEntryDTO() {
    }

    public LogEntryDTO(List<LogEntry> entry, long count) {
        this.entry = entry;
        this.count = count;
    }
}
