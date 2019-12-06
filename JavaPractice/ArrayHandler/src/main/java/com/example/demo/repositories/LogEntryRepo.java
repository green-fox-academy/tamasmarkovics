package com.example.demo.repositories;

import com.example.demo.models.entities.LogEntry;
import org.springframework.data.jpa.repository.Query;
import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;

import java.util.List;


@Repository
public interface LogEntryRepo extends CrudRepository<LogEntry, Long> {

    @Query(value = "SELECT * FROM log_entry WHERE data LIKE :pattern ORDER BY id DESC LIMIT :count OFFSET :page",
            nativeQuery = true)
    List<LogEntry> findAllOrderByCreatedAtDescLimitOffsetPattern(Integer count, Integer page, String pattern);
}
